#!/usr/bin/env python3
"""Portable C++98 checks. Run from any directory: python3 tests/test_all.py."""
from pathlib import Path
import os
import subprocess
import tempfile
import sys

ROOT = Path(__file__).resolve().parents[1]
CXX = os.environ.get('CXX', 'c++')
FLAGS = ['-Wall', '-Wextra', '-Werror', '-std=c++98', '-pedantic-errors']

def run(args, data=None, expected=0):
    result = subprocess.run([str(a) for a in args], input=data, stdout=subprocess.PIPE,
                            stderr=subprocess.PIPE, timeout=30)
    if result.returncode != expected:
        raise RuntimeError(f'{args}: exit {result.returncode}, expected {expected}\n'
                             + result.stdout.decode(errors='replace')
                             + result.stderr.decode(errors='replace'))
    return result.stdout.replace(b'\r\n', b'\n')

def check(ok):
    if not ok:
        raise RuntimeError("Unexpected program output")


def check_behavior(executables):
    exe = executables['cpp0/ex00']
    check(run([exe]) == b'* LOUD AND UNBEARABLE FEEDBACK NOISE *\n')
    check(run([exe, 'Damnit', ' ! ', 'Sorry students.']) == b'DAMNIT ! SORRY STUDENTS.\n')
    check(run([exe, '']) == b'\n')

    exe = executables['cpp0/ex01']
    check(b'Phonebook is empty.' in run([exe], b'SEARCH\nEXIT\n'))
    records = []
    for i in range(9):
        records.extend(['ADD', 'Person' + str(i), 'Lastname', 'NicknameLongerThanTen', '+90 555', 'Secret'])
    result = run([exe], ('\n'.join(records) + '\nSEARCH\n0\nSEARCH\n8\nSEARCH\n1x\nEXIT\n').encode())
    check(b'First name: Person8' in result)
    check(b'Person0' not in result)
    check(b'NicknameL.' in result)
    check(result.count(b'Invalid index.') == 2)
    check(b'A field cannot be empty.' in run([exe], b'ADD\n\n   \nFirst\nLast\nNick\nPhone\nSecret\nEXIT\n'))
    run([exe], b'ADD\nPartial\n')
    run([exe], b'')

    run([sys.executable, ROOT / 'cpp1/ex04/test_replace.py', executables['cpp1/ex04']])


def main():
    exercises = sorted(ROOT.glob('cpp[0-4]/ex[0-9][0-9]'))
    if len(exercises) != 17:
        raise RuntimeError('Expected 17 exercises')
    with tempfile.TemporaryDirectory(prefix='cpp_checks_') as temporary:
        temp = Path(temporary)
        executables = {}
        for folder in exercises:
            key = folder.parent.name + '/' + folder.name
            executable = temp / (key.replace('/', '_') + ('.exe' if os.name == 'nt' else ''))
            run([CXX] + FLAGS + sorted(folder.glob('*.cpp')) + ['-o', executable])
            executables[key] = executable
            # Verify every header can be included independently and twice.
            for hpp in sorted(folder.glob('*.hpp')):
                check = temp / 'header_check.cpp'
                check.write_text(f'#include "{hpp.name}"\n#include "{hpp.name}"\n', encoding='utf-8')
                run([CXX] + FLAGS + ['-I', folder, '-fsyntax-only', check])
            if key not in ['cpp0/ex00', 'cpp0/ex01', 'cpp1/ex04']:
                run([executable])
            print('PASS compile / headers / main:', key, flush=True)

        check_behavior(executables)

        # A real negative compilation test: Animal must be abstract in CPP04/ex02.
        negative = temp / 'abstract_negative.cpp'
        negative.write_text('#include "Animal.hpp"\nint main() { Animal animal; }\n', encoding='utf-8')
        result = subprocess.run([CXX] + FLAGS + ['-I', str(ROOT / 'cpp4/ex02'), '-fsyntax-only', str(negative)],
                                stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=30)
        if result.returncode == 0:
            raise RuntimeError('Animal must be abstract')
        print('PASS behavioral cases and abstract-class rejection', flush=True)
    print('All 17 exercises passed. Linux Makefiles and Valgrind must be checked in WSL.')

if __name__ == '__main__':
    main()

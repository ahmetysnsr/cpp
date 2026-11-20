#!/usr/bin/env python3
"""Run after make: python3 test_replace.py"""
from pathlib import Path
import subprocess
import tempfile
import sys

executable = Path(__file__).resolve().parent / 'replace'
if len(sys.argv) == 2:
    executable = Path(sys.argv[1]).resolve()
with tempfile.TemporaryDirectory() as folder:
    source = Path(folder) / 'input'
    cases = [
        (b'aaaaa\n', 'aa', 'x', b'xxa\n'),
        (b'abab', 'ab', 'abab', b'abababab'),
        (b'abcabc', 'abc', '', b''),
        (b'', 'abc', 'x', b''),
        (b'no match', 'xyz', 'x', b'no match'),
        (b'first\nsecond', 't\ns', 'X', b'firsXecond'),
        (b'a\x00ba\r\n', 'a', 'z', b'z\x00bz\r\n'),
    ]
    for original, search, replacement, expected in cases:
        source.write_bytes(original)
        subprocess.run([str(executable), str(source), search, replacement], check=True)
        if Path(str(source) + '.replace').read_bytes() != expected:
            raise SystemExit(f'Wrong replacement for {original!r}')
        if source.read_bytes() != original:
            raise SystemExit('Input file changed')

    for args in ([source, '', 'x'], [str(source) + '.missing', 'a', 'b'], []):
        if subprocess.run([executable] + args).returncode == 0:
            raise SystemExit(f'Expected failure for {args}')
print('Replacement tests passed.')

# CPP00–CPP04

Her modül ayrı bir teslimdir. Örneğin CPP00 deposunun köküne doğrudan `ex00/`
ve `ex01/` klasörlerini koy.

| Modül | Alıştırmalar |
|---|---|
| CPP00 | ex00–ex01 |
| CPP01 | ex00–ex05 |
| CPP02 | ex00–ex02 |
| CPP03 | ex00–ex02 |
| CPP04 | ex00–ex02 |

WSL'de PhoneBook'u çalıştırmak için:

```sh
cd /mnt/c/Users/Dude/Desktop/cpp/cpp0/ex01
make
./phonebook
make fclean
```

Her Makefile `c++ -Wall -Wextra -Werror -std=c++98` kullanır. CPP01/ex04
klasöründe dosya değiştirme örneklerini `make` ve ardından `python3 test_replace.py`
ile deneyebilirsin. Çalışma klasöründeki toplu kontroller için proje kökünde
`python3 tests/test_all.py` ve `sh tests/check_makefiles.sh` çalıştırılır.

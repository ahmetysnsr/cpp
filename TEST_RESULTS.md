# Son kontrol

17 alıştırmanın tamamı Windows'ta MSVC ile `/W4 /WX` kullanılarak derlendi
ve çalıştırıldı. Clang ayrıca 54 `.cpp` dosyasının tamamını C++98 ve
`-Wall -Wextra -Werror` seçenekleriyle kontrol etti.

Megaphone çıktıları, PhoneBook'ta dokuzuncu kaydın ilk kaydın yerine geçmesi,
boş alanlar, geçersiz indeksler, EOF, dosya değiştirme örnekleri, sabit noktalı
işlemler ve Dog/Cat kopyalarının bağımsızlığı kontrol edildi. Her Makefile'ın
kaynak ve başlık listesi klasör içeriğiyle karşılaştırıldı.

WSL'de GNU Make ile derleme ve Valgrind ile bellek kontrolü ayrıca yapılabilir.

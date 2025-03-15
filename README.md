# Acil Servis Sistemi
  Bir hastanedeki acil servis sistemini yürütmek için gerekli minimum özelliğe sahip bir uygulama.
Bu C programı, bir hastanenin acil servisinde hasta kaydı, ilaç tedavisi, acil servis işlemleri ve taburcu işlemleri gibi temel işlemleri yönetmeyi amaçlayan bir yazılımdır. Sistemde hastaların tanılarına göre hangi servislerin uygun olduğu belirlenir, acil servis işlemleri sırasıyla yapılır ve hastalar taburcu edilir. Program ayrıca, hastaların HL7 formatında kayıtlarını oluşturur ve ilaç bilgilerini kullanıcıya sunar.

## Özellikler

- **Hasta Kaydı**: Hastaların temel bilgileri (isim, TC kimlik numarası, yaş, cinsiyet, tanı vb.) girilerek kaydedilir.
- **Servis Atama**: Tanıya göre hastaların hangi servise yönlendirileceği belirlenir (Kardiyoloji, Nöroloji, Dahiliye vb.).
- **Acil Servis Sıralama**: Hastalar, acil servis önceliklerine göre sıralanır.
- **Recete Numarası Üretimi**: Her hastaya bir recete numarası atanır.
- **HL7 Formatında Hasta Kaydı**: Hasta bilgileri, HL7 formatında yazdırılır.
- **İlaç Bilgisi**: Hastaya verilen ilaçlar hakkında bilgi verilir.
- **Taburcu İşlemi**: Hastalar, tedavi sonrası taburcu edilir.

## Kurulum

1. C derleyicisi kullanarak programı derleyin.
2. Terminal veya komut satırında aşağıdaki komutları kullanarak çalıştırın:

   ```bash
   gcc acil_servis.c -o acil_servis
   ./acil_servis
## Kullanım
Program çalıştırıldığında, kullanıcıdan hasta sayısı istenir.

Ardından her hasta için aşağıdaki bilgiler girilmesi gerekir:

#### İsim: Hastanın adı
#### TC Kimlik No: Hastanın TC kimlik numarası
#### Yaş: Hastanın yaşı
#### Cinsiyet: Hastanın cinsiyeti
#### Tanı: Hastanın tanısı
#### Öncelik: Acil servisteki öncelik durumu (1: yüksek, 2: orta, 3: düşük)
#### İlaç Adı: Hastaya verilecek ilaç adı
#### İlaç Miktarı: İlaç miktarı (mg)
#### İlaç Adedi: Verilecek ilaç adedi
-Sistemdeki hastalar, öncelik sırasına göre sıralanır ve her bir hasta için acil servis işlemleri yapılır.

-HL7 formatında hasta kayıtları yazdırılır.

-İlaç bilgileri yazdırılır.

-Hastalar, ilgili servislerine sevk edilir ve taburcu işlemleri yapılır.

## Dosya Yapısı
#### acil_servis.c: Ana program dosyası.
#### README.md: Bu belge.

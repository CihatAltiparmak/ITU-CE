Bu ödevin 7. case'inin yanlış olduğunu düşünüyorum. Çünkü işlemci, 19 job'a kadar çalıştırabilmekte olup, sıra id'si 17 olan job'a geldiğinde bu job beklemeden direkt işlemcide çalışmalıdır. Ancak src klasöründeki WQ sorgusunda `WQ ` bastırmak yerine `WQ 17` bastırmıştır. Bu da demek oluyor ki case 7 de bir şeyler yanlış.

**edit:** 100 / 17 = 5.8 den her job başına 5 düşüyor. MIPS_THRESHOLD değeri 5 olduğu için 17 id'li job çalıştırılmamalı, bekletilmeli. Bilemedim:/ 

Ödev kodları karışık olabilir. Kusura bakmayınız :) Eğer kodu test etmek istiyorsanız. `cases.zip` dosyasındaki txt leri aşağıda belirtilen dizin yapısına uygun olacak şekilde çıkarınız. Bulunması gereken dosya ve dizinlerin yanlarına yıldız koydum.

```
- include * 
    - Processor.h *
    - Job.h *

- src *
    - Processor.cpp *
    - Job.cpp *
    - main.cpp *
    - testcalico.yaml *

- bin *
    - main

- case_1.txt *
- case_2.txt *
- case_3.txt *
- case_4.txt *
- case_5.txt *
- case_6.txt *
- case_7.txt *
- HW2.pdf
- cases.zip
```

Kodu test etmek için:

```shell
$ pip install calico
$ cd src
$ python -m calico.cli testcalico.yaml
```

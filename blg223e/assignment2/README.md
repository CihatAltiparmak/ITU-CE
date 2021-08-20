TESTCALICO: 13 / 15

Bu ödevin 7. case'inin yanlış olduğunu düşünüyorum. Çünkü işlemci, 19 job'a kadar çalıştırabilmekte olup, sıra id'si 17 olan job'a geldiğinde bu job beklemeden direkt işlemcide çalışmalıdır. Ancak src klasöründeki WQ sorgusunda `WQ ` bastırmak yerine `WQ 17` bastırmıştır. Bu da demek oluyor ki case 7 de bir şeyler yanlış.

**edit:** 100 / 17 = 5.8 den her job başına 5 düşüyor. MIPS_THRESHOLD değeri 5 olduğu için 17 id'li job çalıştırılmamalı, bekletilmeli. Bilemedim:/ 

Ödev kodları karışık olabilir. Kusura bakmayınız :) 

```
blg223e/assignment2
├── bin
│   └── main
├── cases.zip
├── HW2.pdf
├── include
│   ├── Job.h
│   └── Processor.h
├── README.md
└── src
    ├── Job.cpp
    ├── main.cpp
    ├── Processor.cpp
    └── testcalico.yaml
```

Kodu test etmek için:

```shell
$ git clone https://github.com/CihatAltiparmak/ITU-CE.git
$ pip install calico
$ cd ITU-CE/blg223e/assignment2
$ unzip -j cases.zip
$ cd src
$ python -m calico.cli testcalico.yaml
```

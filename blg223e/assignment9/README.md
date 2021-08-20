TESTCALICO: 12/15

Kod bütün caseleri geçemiyor (case_4 te takılıyor), bu ödevi iyi yapamadım. Müsait bir vakitte tekrar bakacağım.

```
blg223e/assignment9
├── bin
│   └── main
├── cases.zip
├── HW9.pdf
├── include
│   ├── MultiNode.h
│   └── SkipList.h
├── README.md
└── src
    ├── main.cpp
    ├── MultiNode.cpp
    ├── SkipList.cpp
    └── testcalico.yaml
```

Kodu test etmek için:

```shell
$ git clone https://github.com/CihatAltiparmak/ITU-CE.git
$ pip install calico
$ cd ITU-CE/blg223e/assignment9
$ unzip -j cases.zip
$ cd src
$ python -m calico.cli testcalico.yaml
```

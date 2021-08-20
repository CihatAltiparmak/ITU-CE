TESTCALICO: 15/15

```
blg223e/assignment1
├── bin
│   └── main
├── cases.zip
├── HW1.pdf
├── include
│   └── ExpandingArray.h
├── README.md
└── src
    ├── ExpandingArray.cpp
    ├── main.cpp
    └── testcalico.yaml
```

Kodu test etmek için:

```shell
$ git clone https://github.com/CihatAltiparmak/ITU-CE.git
$ pip install calico
$ cd ITU-CE/blg223e/assignment1
$ unzip -j cases.zip
$ cd src
$ python -m calico.cli testcalico.yaml
```

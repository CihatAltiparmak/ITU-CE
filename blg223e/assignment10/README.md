TESTCALICO: 15/15
Kod bütün caseleri geçiyor. Allah'a emanet kod yazdık ama.

```
blg223e/assignment10
├── bin
│   └── main
├── cases.zip
├── HW10.pdf
├── include
│   ├── RBNode.h
│   └── RBVector.h
├── README.md
└── src
    ├── main.cpp
    ├── RBNode.cpp
    ├── RBVector.cpp
    └── testcalico.yaml
```

Kodu test etmek için:

```shell
$ git clone https://github.com/CihatAltiparmak/ITU-CE.git
$ pip install calico
$ cd ITU-CE/blg223e/assignment10
$ unzip -j cases.zip
$ cd src
$ python -m calico.cli testcalico.yaml
```

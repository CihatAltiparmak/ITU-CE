TESTCALICO: 15 / 15

Kod bütün case'leri geçmekle birlikte valgrind ile kontrol ettiğimde yazdığım kodda memory leak olduğunu fark ettim. Bunu bir ara düzeltirim.

```
blg223e/assignment3
├── bin
│   └── main
├── cases.zip
├── HW3.pdf
├── include
│   ├── BlockList.h
│   ├── BlockNode.h
│   ├── md5.h
│   └── Node.h
├── README.md
└── src
    ├── BlockList.cpp
    ├── BlockNode.cpp
    ├── main.cpp
    ├── md5.cpp
    ├── Node.cpp
    └── testcalico.yaml
```

Kodu test etmek için:

```shell
$ git clone https://github.com/CihatAltiparmak/ITU-CE.git
$ pip install calico
$ cd ITU-CE/blg223e/assignment3
$ unzip -j cases.zip
$ cd src
$ python -m calico.cli testcalico.yaml
```

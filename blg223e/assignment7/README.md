Kod sadece case_5'i geçemiyor. Nedenini anlayabilmiş değilim.

```
blg223e/assignment7
├── bin
│   └── main
├── cases.txt.zip
├── HW7.pdf
├── include
│   └── Heap.h
├── README.md
└── src
    ├── Heap.cpp
    ├── main.cpp
    └── testcalico.yaml
```

Kodu test etmek için:

```shell
$ git clone https://github.com/CihatAltiparmak/ITU-CE.git
$ pip install calico
$ cd ITU-CE/blg223e/assignment7
$ unzip -j cases.zip
$ cd src
$ python -m calico.cli testcalico.yaml
```

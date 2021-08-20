TESTCALICO: 15/15

Kod bütün case'leri geçiyor. 

```
blg223e/assignment6
├── bin
│   └── main
├── cases.zip
├── HW6.pdf
├── include
│   ├── Trie.h
│   └── TrieNode.h
├── README.md
└── src
    ├── main.cpp
    ├── testcalico.yaml
    ├── Trie.cpp
    └── TrieNode.cpp
```

Kodu test etmek için:

```shell
$ git clone https://github.com/CihatAltiparmak/ITU-CE.git
$ pip install calico
$ cd ITU-CE/blg223e/assignment6
$ unzip -j cases.zip
$ cd src
$ python -m calico.cli testcalico.yaml --timeout 3
```

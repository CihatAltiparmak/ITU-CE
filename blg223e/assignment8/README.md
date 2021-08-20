TESTCALICO: 15/15

HW GRADE: 13/15 

(Demek ki yeteri kadar efektif değilmiş :))

Kod bütün caseleri geçiyor ama kodun efektifliğini bilemiyorum.

İleride kendi yazdığım caseleri de buraya yükleyebilirim.(Yüklemeyebilirim de, Çok mb :/)

```
blg223e/assignment8
├── bin
├── cases.zip
├── HW8.pdf
├── README.md
└── src
    ├── main.cpp
    └── testcalico.yaml
```

Kodu test etmek için:

```shell
$ git clone https://github.com/CihatAltiparmak/ITU-CE.git
$ pip install calico
$ cd ITU-CE/blg223e/assignment8
$ unzip -j cases.zip
$ cd src
$ python -m calico.cli testcalico.yaml
```

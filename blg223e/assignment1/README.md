Eğer kodu test etmek istiyorsanız. `cases.zip` dosyasındaki txt leri aşağıda belirtilen dizin yapısına uygun olacak şekilde çıkarınız. Bulunması gereken dosya ve dizinlerin yanlarına yıldız koydum.

```
- include * 
    - ExpandingArray.h *

- src *
    - ExpandingArray.cpp *
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
- HW1.pdf
- cases.zip
```

Kodu test etmek için:

```shell
$ pip install calico
$ cd src
$ python -m calico.cli testcalico.yaml
```
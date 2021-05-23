#!/usr/bin/env python3

import sys
import string as String
import random

f = open("input", 'w')
lines = sys.argv[1]
entities = []
for i in range(int(lines)):
    entity = ''.join(random.choice(String.ascii_letters) for x in range(6))
    entities.append(entity)
    string = "addent {0}\n".format(entity)
    p = random.uniform(0, 1)
    if p <= 0.33:
        rand = random.randint(0, len(entities)-1)
        string = "delent {0}\n".format(entities[rand])
        if p <= 0.1:
            string = "delent {0}\n".format(entity)
    f.write(string)

#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Gluster module to generate the sha256 checksum for all the files in the dir."""

from gluster import gfapi
from hashlib import sha256
import os

# Create virtual mount
host = '192.168.0.106'
vol = 'testvol'

volume = gfapi.Volume(host, vol)
volume.mount()
result = dict()
for path, dirnames, filenames in volume.walk('/'):
    for _file in filenames:
        abs_path = os.path.join(path, _file)
        with volume.fopen(abs_path, 'rb') as f:
            file_content = f.read()
            result[abs_path] = sha256(file_content).hexdigest()

__import__('pprint').pprint(result)

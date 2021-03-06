/**
* Tencent is pleased to support the open source community by making DCache available.
* Copyright (C) 2019 THL A29 Limited, a Tencent company. All rights reserved.
* Licensed under the BSD 3-Clause License (the "License"); you may not use this file
* except in compliance with the License. You may obtain a copy of the License at
*
* https://opensource.org/licenses/BSD-3-Clause
*
* Unless required by applicable law or agreed to in writing, software distributed under
* the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
* either express or implied. See the License for the specific language governing permissions
* and limitations under the License.
*/
#include "MKHash.h"

unsigned int MKHash::HashRawString(const string &key)
{
    const char *ptr = key.c_str();
    size_t key_length = key.length();
    unsigned int value = 0;

    while (key_length--)
    {
        value += *ptr++;
        value += (value << 10);
        value ^= (value >> 6);
    }
    value += (value << 3);
    value ^= (value >> 11);
    value += (value << 15);

    return value == 0 ? 1 : value;
}

unsigned int MKHash::HashMK(const string &key)
{
    unsigned int uHash = HashRawString(key);

    return uHash;
}

unsigned int MKHash::HashMKUK(const string &key)
{
    unsigned int uHash = HashRawString(key);
    return uHash;
}

//
// Copyright 2016 Jeff Bush
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#pragma once

#include "fs.h"
#include "vm_area_map.h"
#include "vm_translation_map.h"

struct vm_address_space
{
    spinlock_t lock;
    struct vm_area_map area_map;
    struct vm_translation_map *translation_map;
};

struct vm_address_space *get_kernel_address_space(void);
void vm_address_space_init(struct vm_translation_map *init_map);
struct vm_address_space *create_address_space(void);
struct vm_area *create_area(struct vm_address_space*, unsigned int address,
    unsigned int size, enum placement place, const char *name,
    unsigned int flags, struct file_handle *file);
int handle_page_fault(unsigned int address);

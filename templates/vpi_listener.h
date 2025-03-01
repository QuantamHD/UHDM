/*
 Do not modify, auto-generated by model_gen.tcl

 Copyright 2019-2020 Alain Dargelas

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

/*
 * File:   vpi_listener.h
 * Author:
 *
 * Created on December 14, 2019, 10:03 PM
 */

#ifndef UHDM_VPI_LISTENER_H
#define UHDM_VPI_LISTENER_H

#include <uhdm/BaseClass.h>
#include <uhdm/sv_vpi_user.h>

namespace UHDM {

class VpiListener;
void listen_designs (const std::vector<vpiHandle>& designs, VpiListener* listener);

void listen_any(vpiHandle object, VpiListener* listener, VisitedContainer* visited);

<VPI_LISTENERS_HEADER>

 };

#endif

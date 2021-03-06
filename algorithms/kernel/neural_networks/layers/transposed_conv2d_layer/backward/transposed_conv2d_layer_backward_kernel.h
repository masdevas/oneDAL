/* file: transposed_conv2d_layer_backward_kernel.h */
/*******************************************************************************
* Copyright 2014-2019 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

//++
//  Declaration of template function that calculate transposed convolution 2d.
//--


#ifndef __TRANSPOSED_CONV2D_LAYER_BACKWARD_KERNEL_H__
#define __TRANSPOSED_CONV2D_LAYER_BACKWARD_KERNEL_H__

#include "neural_networks/layers/transposed_conv2d/transposed_conv2d_layer.h"
#include "neural_networks/layers/transposed_conv2d/transposed_conv2d_layer_types.h"
#include "kernel.h"
#include "service_math.h"
#include "numeric_table.h"

using namespace daal::data_management;
using namespace daal::services;

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace layers
{
namespace transposed_conv2d
{
namespace backward
{
namespace internal
{

/**
 *  \brief Kernel for transposed convolution 2d calculation
 */
template<typename algorithmFPType, Method method, CpuType cpu>
class TransposedConv2dKernel : public Kernel
{
public:
    services::Status compute(const Tensor &inGradTensor, const Tensor &xTensor, const Tensor &wTensor,
        const transposed_conv2d::Parameter &parameter, Tensor &wDerTensor, Tensor &bDerTensor, Tensor &resultTensor);
};

} // internal
} // backward
} // transposed_conv2d
} // layers
} // neural_networks
} // algorithms
} // daal

#endif

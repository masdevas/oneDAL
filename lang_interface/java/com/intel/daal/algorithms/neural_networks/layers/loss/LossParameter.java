/* file: LossParameter.java */
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

/**
 * @ingroup loss
 * @{
 */
/**
 * @brief Contains classes for the neural network layers
 */
package com.intel.daal.algorithms.neural_networks.layers.loss;

import com.intel.daal.utils.*;
import com.intel.daal.utils.*;
import com.intel.daal.services.DaalContext;
import com.intel.daal.algorithms.neural_networks.initializers.InitializerIface;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__LOSS__LOSSPARAMETER"></a>
 * @brief Class that specifies parameters of the neural network layer
 */
public class LossParameter extends com.intel.daal.algorithms.neural_networks.layers.Parameter {
    /** @private */
    static {
        LibUtils.loadLibrary();
    }

    /**
     * Constructs the parameter of the loss layer
     * @param context Context to manage the parameter of the loss layer
     */
    public LossParameter(DaalContext context) {
        super(context);
    }

    public LossParameter(DaalContext context, long cParameter) {
        super(context, cParameter);
    }
}
/** @} */

/* file: Convolution2dLayerDataId.java */
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
 * @ingroup convolution2d
 * @{
 */
package com.intel.daal.algorithms.neural_networks.layers.convolution2d;

import java.lang.annotation.Native;

import com.intel.daal.utils.*;
/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__CONVOLUTION2D__CONVOLUTION2DLAYERDATAID"></a>
 * \brief Identifiers of input objects for the backward 2D convolution layer and results for the forward 2D convolution layer
 */
public final class Convolution2dLayerDataId {
    /** @private */
    static {
        LibUtils.loadLibrary();
    }

    private int _value;

    /**
     * Constructs the input object identifier using the provided value
     * @param value     Value corresponding to the input object identifier
     */
    public Convolution2dLayerDataId(int value) {
        _value = value;
    }

    /**
     * Returns the value corresponding to the input object identifier
     * @return Value corresponding to the input object identifier
     */
    public int getValue() {
        return _value;
    }

    @Native private static final int auxDataId = 0;
    @Native private static final int auxWeightsId = 1;

    public static final Convolution2dLayerDataId auxData    = new Convolution2dLayerDataId(auxDataId);    /*!< Data processed at the forward stage of the layer */
    public static final Convolution2dLayerDataId auxWeights = new Convolution2dLayerDataId(auxWeightsId); /*!< Weights of the 2D convolution layer */
}
/** @} */

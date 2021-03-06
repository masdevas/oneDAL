/* file: StochasticPooling2dParameter.java */
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
 * @ingroup stochastic_pooling2d
 * @{
 */
package com.intel.daal.algorithms.neural_networks.layers.stochastic_pooling2d;

import com.intel.daal.services.DaalContext;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__STOCHASTIC_POOLING2D__STOCHASTICPOOLING2DPARAMETER"></a>
 * \brief Class that specifies parameters of the two-dimensional stochastic pooling layer
 */
public class StochasticPooling2dParameter extends com.intel.daal.algorithms.neural_networks.layers.pooling2d.Pooling2dParameter {
    /** @private */
    public StochasticPooling2dParameter(DaalContext context, long cObject) {
        super(context, cObject);
    }

    /**
     * @DAAL_DEPRECATED
     *  Returns seed for multinomial distribution random number generator
     */
    public long getSeed() {
        return cGetSeed(cObject);
    }

    /**
     * @DAAL_DEPRECATED
     *  Sets the seed for multinomial distribution random number generator
     *  @param seed Seed for multinomial distribution random number generator
     */
    public void setSeed(long seed) {
        cSetSeed(cObject, seed);
    }

    /**
     *  Gets the flag that specifies whether the layer is used for the prediction stage or not
     */
    public boolean getPredictionStage() {
        return cGetPredictionStage(cObject);
    }

    /**
     *  Sets the flag that specifies whether the layer is used for the prediction stage or not
     *  @param predictionStage Flag that specifies whether the layer is used for the prediction stage or not
     */
    public void setPredictionStage(boolean predictionStage) {
        cSetPredictionStage(cObject, predictionStage);
    }

    /**
     * Sets the engine for multinomial distribution random number generator
     * @param engine for multinomial distribution random number generator
     */
    public void setEngine(com.intel.daal.algorithms.engines.BatchBase engine) {
        cSetEngine(cObject, engine.cObject);
    }

    private native void cSetEngine(long cObject, long cEngineObject);
    private native long   cGetSeed(long cParameter);
    private native void   cSetSeed(long cParameter, long seed);
    private native boolean cGetPredictionStage(long cParameter);
    private native void    cSetPredictionStage(long cParameter, boolean predictionStage);
}
/** @} */

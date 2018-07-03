/* file: TanhLayerDataId.java */
/*******************************************************************************
* Copyright 2014-2018 Intel Corporation.
*
* This software and the related documents are Intel copyrighted  materials,  and
* your use of  them is  governed by the  express license  under which  they were
* provided to you (License).  Unless the License provides otherwise, you may not
* use, modify, copy, publish, distribute,  disclose or transmit this software or
* the related documents without Intel's prior written permission.
*
* This software and the related documents  are provided as  is,  with no express
* or implied  warranties,  other  than those  that are  expressly stated  in the
* License.
*******************************************************************************/

/**
 * @ingroup tanh_layers
 * @{
 */
package com.intel.daal.algorithms.neural_networks.layers.tanh;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__TANH__TANHLAYERDATAID"></a>
 * \brief Identifiers of input objects for the backward hyperbolic tangent (tanh) layer and results for the forward tanh layer
 */
public final class TanhLayerDataId {
    /** @private */
    static {
        System.loadLibrary("JavaAPI");
    }

    private int _value;

    /**
     * Constructs the input object identifier using the provided value
     * @param value     Value corresponding to the input object identifier
     */
    public TanhLayerDataId(int value) {
        _value = value;
    }

    /**
     * Returns the value corresponding to the input object identifier
     * @return Value corresponding to the input object identifier
     */
    public int getValue() {
        return _value;
    }

    private static final int auxValueId = 2;

    public static final TanhLayerDataId auxValue = new TanhLayerDataId(auxValueId); /*!< Value computed at the forward stage of the layer */
}
/** @} */

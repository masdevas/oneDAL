/* file: ForwardInputId.java */
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
 * @ingroup layers_forward
 * @{
 */
package com.intel.daal.algorithms.neural_networks.layers;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__FORWARDINPUTID"></a>
 * \brief Available identifiers of input objects for the forward layer
 */
public final class ForwardInputId {
    /** @private */
    static {
        System.loadLibrary("JavaAPI");
    }

    private int _value;

    /**
     * Constructs the input object identifier using the provided value
     * @param value     Value corresponding to the input object identifier
     */
    public ForwardInputId(int value) {
        _value = value;
    }

    /**
     * Returns the value corresponding to the input object identifier
     * @return Value corresponding to the input object identifier
     */
    public int getValue() {
        return _value;
    }

    private static final int dataId = 0;
    private static final int weightsId = 1;
    private static final int biasesId = 2;

    public static final ForwardInputId data = new ForwardInputId(dataId); /*!< Input data */
    public static final ForwardInputId weights = new ForwardInputId(weightsId); /*!< Weights of the neural network layer */
    public static final ForwardInputId biases = new ForwardInputId(biasesId); /*!< Biases of the neural network layer */
}
/** @} */

/* file: MaximumPooling2dBackwardInput.java */
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
 * @defgroup maximum_pooling2d_backward Backward Two-dimensional Max Pooling Layer
 * @brief Contains classes for backward maximum 2D pooling layer
 * @ingroup maximum_pooling2d
 * @{
 */
package com.intel.daal.algorithms.neural_networks.layers.maximum_pooling2d;

import com.intel.daal.services.DaalContext;
import com.intel.daal.data_management.data.Factory;
import com.intel.daal.data_management.data.Tensor;
import com.intel.daal.data_management.data.NumericTable;
import com.intel.daal.data_management.data.Factory;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__MAXIMUM_POOLING2D__MAXIMUMPOOLING2DBACKWARDINPUT"></a>
 * @brief Input object for the backward two-dimensional maximum pooling layer
 */
public final class MaximumPooling2dBackwardInput extends com.intel.daal.algorithms.neural_networks.layers.pooling2d.Pooling2dBackwardInput {
    /** @private */
    static {
        System.loadLibrary("JavaAPI");
    }

    public MaximumPooling2dBackwardInput(DaalContext context, long cObject) {
        super(context, cObject);
    }

    /**
     * Sets the input object of the backward two-dimensional maximum pooling layer
     * @param id    Identifier of the input object
     * @param val   Value of the input object
     */
    public void set(MaximumPooling2dLayerDataId id, Tensor val) {
        if (id == MaximumPooling2dLayerDataId.auxSelectedIndices) {
            cSetInput(cObject, id.getValue(), val.getCObject());
        }
        else {
            throw new IllegalArgumentException("Incorrect MaximumPooling2dBackwardInputId");
        }
    }

    /**
     * Sets the input object of the backward two-dimensional maximum pooling layer
     * @param id    Identifier of the input object
     * @param val   Value of the input object
     */
    public void set(MaximumPooling2dLayerDataNumericTableId id, NumericTable val) {
        if (id == MaximumPooling2dLayerDataNumericTableId.auxInputDimensions) {
            cSetInputNumericTable(cObject, id.getValue(), val.getCObject());
        }
        else {
            throw new IllegalArgumentException("Incorrect MaximumPooling2dBackwardInputId");
        }
    }

    /**
     * Returns the input object of the backward two-dimensional maximum pooling layer
     * @param id Identifier of the input object
     * @return   Input object that corresponds to the given identifier
     */
    public Tensor get(MaximumPooling2dLayerDataId id) {
        if (id == MaximumPooling2dLayerDataId.auxSelectedIndices) {
            return (Tensor)Factory.instance().createObject(getContext(), cGetInput(cObject, id.getValue()));
        }
        else {
            throw new IllegalArgumentException("id unsupported");
        }
    }

    /**
     * Returns the input object of the backward two-dimensional maximum pooling layer
     * @param id Identifier of the input object
     * @return   Input object that corresponds to the given identifier
     */
    public NumericTable get(MaximumPooling2dLayerDataNumericTableId id) {
        if (id == MaximumPooling2dLayerDataNumericTableId.auxInputDimensions) {
            return (NumericTable)Factory.instance().createObject(getContext(), cGetInputNumericTable(cObject, id.getValue()));
        }
        else {
            throw new IllegalArgumentException("id unsupported");
        }
    }

    private native void cSetInput(long cObject, int id, long ntAddr);
    private native long cGetInput(long cObject, int id);
    private native void cSetInputNumericTable(long cObject, int id, long ntAddr);
    private native long cGetInputNumericTable(long cObject, int id);
}
/** @} */

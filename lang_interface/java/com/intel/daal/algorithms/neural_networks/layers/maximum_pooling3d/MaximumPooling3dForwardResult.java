/* file: MaximumPooling3dForwardResult.java */
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
 * @ingroup maximum_pooling3d_forward
 * @{
 */
package com.intel.daal.algorithms.neural_networks.layers.maximum_pooling3d;

import com.intel.daal.data_management.data.Factory;
import com.intel.daal.data_management.data.Tensor;
import com.intel.daal.data_management.data.NumericTable;
import com.intel.daal.data_management.data.Factory;
import com.intel.daal.services.DaalContext;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__MAXIMUM_POOLING3D__MAXIMUMPOOLING3DFORWARDRESULT"></a>
 * @brief Class that provides methods to access the result obtained with the compute() method of the
 * forward three-dimensional maximum pooling layer
 */
public final class MaximumPooling3dForwardResult extends com.intel.daal.algorithms.neural_networks.layers.pooling3d.Pooling3dForwardResult {
    /** @private */
    static {
        System.loadLibrary("JavaAPI");
    }

    /**
     * Constructs the forward three-dimensional maximum pooling layer result
     * @param context   Context to manage the forward three-dimensional maximum pooling layer result
     */
    public MaximumPooling3dForwardResult(DaalContext context) {
        super(context);
        this.cObject = cNewResult();
    }

    public MaximumPooling3dForwardResult(DaalContext context, long cObject) {
        super(context, cObject);
    }

    /**
     * Returns the result of the forward three-dimensional maximum pooling layer
     * @param  id   Identifier of the result
     * @return Result that corresponds to the given identifier
     */
    public Tensor get(MaximumPooling3dLayerDataId id) {
        if (id == MaximumPooling3dLayerDataId.auxSelectedIndices) {
            return (Tensor)Factory.instance().createObject(getContext(), cGetValue(cObject, id.getValue()));
        }
        else {
            throw new IllegalArgumentException("id unsupported");
        }
    }

    /**
     * Returns the result of the forward three-dimensional maximum pooling layer
     * @param  id   Identifier of the result
     * @return Result that corresponds to the given identifier
     */
    public NumericTable get(MaximumPooling3dLayerDataNumericTableId id) {
        if (id == MaximumPooling3dLayerDataNumericTableId.auxInputDimensions) {
            return (NumericTable)Factory.instance().createObject(getContext(), cGetNumericTableValue(cObject, id.getValue()));
        }
        else {
            throw new IllegalArgumentException("id unsupported");
        }
    }

    /**
     * Sets the result of the forward three-dimensional maximum pooling layer
     * @param id   Identifier of the result
     * @param val  Result that corresponds to the given identifier
     */
    public void set(MaximumPooling3dLayerDataId id, Tensor val) {
        if (id == MaximumPooling3dLayerDataId.auxSelectedIndices) {
            cSetValue(cObject, id.getValue(), val.getCObject());
        }
        else {
            throw new IllegalArgumentException("id unsupported");
        }
    }

    /**
     * Sets the result of the forward three-dimensional maximum pooling layer
     * @param id   Identifier of the result
     * @param val  Result that corresponds to the given identifier
     */
    public void set(MaximumPooling3dLayerDataNumericTableId id, NumericTable val) {
        if (id == MaximumPooling3dLayerDataNumericTableId.auxInputDimensions) {
            cSetValue(cObject, id.getValue(), val.getCObject());
        }
        else {
            throw new IllegalArgumentException("id unsupported");
        }
    }

    private native long cNewResult();
    private native long cGetValue(long cObject, int id);
    private native void cSetValue(long cObject, int id, long ntAddr);
    private native long cGetNumericTableValue(long cObject, int id);
    private native void cSetNumericTableValue(long cObject, int id, long ntAddr);
}
/** @} */

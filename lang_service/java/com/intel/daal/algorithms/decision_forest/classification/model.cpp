/* file: model.cpp */
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

/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>

#include "daal.h"
#include "decision_forest/classification/JModel.h"
#include "common_helpers.h"
#include "common_helpers_functions.h"
#include "../../classifier/tree_node_visitor.h"

USING_COMMON_NAMESPACES()
namespace dfc = daal::algorithms::decision_forest::classification;

/*
* Class:     com_intel_daal_algorithms_decision_forest_classification_Model
* Method:    cGetNumberOfTrees
* Signature: (J)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_decision_1forest_classification_Model_cGetNumberOfTrees
(JNIEnv *, jobject, jlong modAddr)
{
    return (jlong)(*(dfc::ModelPtr *)modAddr)->numberOfTrees();
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_classification_Model
* Method:    cTraverseDF
* Signature: (JJLcom/intel/daal/algorithms/decision_forest/classification/NodeVisitor;)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_decision_1forest_classification_Model_cTraverseDF
(JNIEnv *env, jobject, jlong modAddr, jlong iTree, jobject visitor)
{
    JavaVM *jvm;
    // Get pointer to the Java VM interface function table
    jint status = env->GetJavaVM(&jvm);
    if(status != 0)
        throwError(env, "Couldn't get Java VM interface");
    daal::classification::JavaTreeNodeVisitor visitorImpl(jvm, visitor);
    (*(dfc::ModelPtr *)modAddr)->traverseDF((size_t)iTree, visitorImpl);
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_classification_Model
* Method:    cTraverseBF
* Signature: (JJLcom/intel/daal/algorithms/decision_forest/classification/NodeVisitor;)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_decision_1forest_classification_Model_cTraverseBF
(JNIEnv *env, jobject, jlong modAddr, jlong iTree, jobject visitor)
{
    JavaVM *jvm;
    // Get pointer to the Java VM interface function table
    jint status = env->GetJavaVM(&jvm);
    if(status != 0)
        throwError(env, "Couldn't get Java VM interface");
    daal::classification::JavaTreeNodeVisitor visitorImpl(jvm, visitor);
    (*(dfc::ModelPtr *)modAddr)->traverseBF((size_t)iTree, visitorImpl);
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_classification_Model
* Method:    cClear
* Signature: (J)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_decision_1forest_classification_Model_cClear
(JNIEnv *, jobject, jlong modAddr)
{
    (*(dfc::ModelPtr *)modAddr)->clear();
}

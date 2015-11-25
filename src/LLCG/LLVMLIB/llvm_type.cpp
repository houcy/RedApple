/* 
* @Author: sxf
* @Date:   2015-11-24 15:40:26
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-25 16:54:37
*/

#include "llvm_type.h"
#include "llvm/IR/DerivedTypes.h"

using namespace llvm;

llvm_type::llvm_type(llvm::Type* v) {
	data = v;
}

llvm_type::~llvm_type() {

}

bool llvm_type::isStructType() {
	return data->isStructTy();
}


string llvm_type::getTypeName() {
	if (data->isStructTy()) {
		StructType* st = (StructType*) data;
		return st->getName().str();		
	}
	return "";
}
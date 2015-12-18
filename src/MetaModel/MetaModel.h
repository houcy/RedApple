/* 
* @Author: sxf
* @Date:   2015-11-13 17:08:01
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-14 17:17:14
*/


#ifndef META_MODEL_H
#define META_MODEL_H

#include <string>
#include "LLCG/lvalue.h"

typedef struct cJSON cJSON;

enum MetaType
{
	struct_meta_t, function_meta_t, macro_meta_t
};

class CodeGenContext;

/**
 * @brief 元数据模型基类
 */
class MetaModel : public lvalue
{
public:
	MetaModel(std::string);
	~MetaModel();

	virtual void insertToST(CodeGenContext* context) = 0;
	virtual void genCode(CodeGenContext* context) = 0;
	virtual cJSON* genJson() = 0;
	virtual void genMetaCode(CodeGenContext* context) = 0;
	virtual MetaType getMetaType() = 0;

	static MetaModel* readJson(cJSON*);
	static MetaModel* readMetaCode();

	virtual bool isStructType() {
		return false;
	}

	// 当前为值时，获取当前的类型
	virtual LValue getType() {
		return NULL;
	}

	// 当前为值或类型,都能获得对应的名称
	virtual string getTypeName() {
		return "";
	}

	// 当前为类型时, 返回一个新的指针类型
	virtual LValue getPointerTo() {
		return NULL;
	}

protected:
	std::string name;
};



#endif // META_MODEL_H

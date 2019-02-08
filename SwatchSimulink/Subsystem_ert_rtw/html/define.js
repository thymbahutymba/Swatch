function CodeDefine() { 
this.def = new Array();
this.def["Subsys_enter_internal_Stopwatch"] = {file: "Subsystem_c.html",line:61,type:"fcn"};this.def["Subsystem_Interface"] = {file: "Subsystem_c.html",line:96,type:"fcn"};this.def["Subsyste_chartstep_c3_Subsystem"] = {file: "Subsystem_c.html",line:413,type:"fcn"};this.def["Subsystem_step"] = {file: "Subsystem_c.html",line:573,type:"fcn"};this.def["Subsystem_initialize"] = {file: "Subsystem_c.html",line:748,type:"fcn"};this.def["Subsystem"] = {file: "Subsystem_c.html",line:778,type:"fcn"};this.def["DW_Subsystem_T"] = {file: "Subsystem_h.html",line:85,type:"type"};this.def["PrevZCX_Subsystem_T"] = {file: "Subsystem_h.html",line:90,type:"type"};this.def["RT_MODEL_Subsystem_T"] = {file: "Subsystem_types_h.html",line:24,type:"type"};this.def["int8_T"] = {file: "rtwtypes_h.html",line:50,type:"type"};this.def["uint8_T"] = {file: "rtwtypes_h.html",line:51,type:"type"};this.def["int16_T"] = {file: "rtwtypes_h.html",line:52,type:"type"};this.def["uint16_T"] = {file: "rtwtypes_h.html",line:53,type:"type"};this.def["int32_T"] = {file: "rtwtypes_h.html",line:54,type:"type"};this.def["uint32_T"] = {file: "rtwtypes_h.html",line:55,type:"type"};this.def["boolean_T"] = {file: "rtwtypes_h.html",line:61,type:"type"};this.def["int_T"] = {file: "rtwtypes_h.html",line:62,type:"type"};this.def["uint_T"] = {file: "rtwtypes_h.html",line:63,type:"type"};this.def["ulong_T"] = {file: "rtwtypes_h.html",line:64,type:"type"};this.def["char_T"] = {file: "rtwtypes_h.html",line:65,type:"type"};this.def["uchar_T"] = {file: "rtwtypes_h.html",line:66,type:"type"};this.def["byte_T"] = {file: "rtwtypes_h.html",line:67,type:"type"};this.def["pointer_T"] = {file: "rtwtypes_h.html",line:85,type:"type"};this.def["ZCDirection"] = {file: "zero_crossing_types_h.html",line:29,type:"type"};this.def["ZCSigState"] = {file: "zero_crossing_types_h.html",line:32,type:"type"};this.def["ZCEventType"] = {file: "zero_crossing_types_h.html",line:45,type:"type"};}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["Subsystem_c.html"] = "../Subsystem.c";
	this.html2Root["Subsystem_c.html"] = "Subsystem_c.html";
	this.html2SrcPath["Subsystem_h.html"] = "../Subsystem.h";
	this.html2Root["Subsystem_h.html"] = "Subsystem_h.html";
	this.html2SrcPath["Subsystem_private_h.html"] = "../Subsystem_private.h";
	this.html2Root["Subsystem_private_h.html"] = "Subsystem_private_h.html";
	this.html2SrcPath["Subsystem_types_h.html"] = "../Subsystem_types.h";
	this.html2Root["Subsystem_types_h.html"] = "Subsystem_types_h.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.html2SrcPath["zero_crossing_types_h.html"] = "../zero_crossing_types.h";
	this.html2Root["zero_crossing_types_h.html"] = "zero_crossing_types_h.html";
	this.html2SrcPath["rtmodel_h.html"] = "../rtmodel.h";
	this.html2Root["rtmodel_h.html"] = "rtmodel_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"Subsystem_c.html","Subsystem_h.html","Subsystem_private_h.html","Subsystem_types_h.html","rtwtypes_h.html","zero_crossing_types_h.html","rtmodel_h.html"];

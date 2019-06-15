package main

import (
	"C"
	"crypto/md5"
	"encoding/hex"
	"unicode"

	"github.com/mozillazg/go-pinyin"
)

//export convertCode
func convertCode(value string) *C.char {
	stringSlice := []rune(value)
	convertedCode := ""
	// Support Chinese words in quotation
	quotationFlag := false
	tempID := ""
	keywords := []string{"字符", "其他", "枚举", "如果", "整型", "返回", "占用空间", "循环当", "打开",
		"读取", "关闭", "打印", "内存分配", "内存设置", "内存拷贝", "退出", "空值", "主函数"}
	for i := 0; i < len(stringSlice); i++ {
		ch := string(stringSlice[i])
		if ch == "\"" {
			quotationFlag = !quotationFlag
			convertedCode += ch
			continue
		} else if quotationFlag == true {
			convertedCode += ch
			continue
		}

		if unicode.Is(unicode.Scripts["Han"], stringSlice[i]) || unicode.IsLetter(stringSlice[i]) || ch == "_" {
			tempID += ch
		} else {
			if tempID != "" {
				if unicode.IsDigit(stringSlice[i]) {
					tempID += ch
					continue
				}
				if stringsContains(keywords, tempID) == -1 {
					convertedCode += "_" + getMD5HashCode(tempID)
				} else {
					for _, h := range pinyin.LazyConvert(tempID, nil) {
						convertedCode += h
					}
				}
			}
			convertedCode += ch
			tempID = ""
			continue
		}
	}
	return C.CString(convertedCode)
}

func stringsContains(array []string, val string) (index int) {
	index = -1
	for i := 0; i < len(array); i++ {
		if array[i] == val {
			index = i
			return
		}
	}
	return
}

func getMD5HashCode(tempID string) string {
	hash := md5.New()
	hash.Write([]byte(tempID))
	bytes := hash.Sum(nil)
	hashCode := hex.EncodeToString(bytes)
	return hashCode
}

func main() {
}

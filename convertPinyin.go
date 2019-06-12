package main

import (
	"C"
	"unicode"
	"fmt"

	"github.com/mozillazg/go-pinyin"
)

//export convertPinyin
func convertPinyin(value string) *C.char {
	stringSlice := []rune(value)
	convertedCode := ""
	for i := 0; i < len(stringSlice); i++ {
		ch := string(stringSlice[i])
		if unicode.Is(unicode.Scripts["Han"], stringSlice[i]) {
			convertedCode += pinyin.LazyConvert(ch, nil)[0]
		} else {
			convertedCode += ch
		}
	}
	fmt.Println("convertedCode")
	return C.CString(convertedCode)
}

func main() {
}

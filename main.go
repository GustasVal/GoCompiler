package main

import (
	"LookSharp/ast"
	"LookSharp/checker"
	"LookSharp/gen"
	"LookSharp/lexer"
	"LookSharp/parser"
	"bytes"
	"fmt"
	"io/ioutil"
	"os"
	"os/exec"
	"path/filepath"
)

func check(err error) {
	if err != nil {
		panic(err)
	}
}

func Parse(input string) *ast.Program {
	l := lexer.NewLexer([]byte(input))
	p := parser.NewParser()
	node, err := p.Parse(l)
	check(err)
	program, _ := node.(*ast.Program)
	return program
}

func TypeCheck(program *ast.Program) {
	err := checker.Checker(program)
	check(err)
}

func Compile(code bytes.Buffer) string {
	f, err := os.Create("./build/" + "main" + ".cpp")
	check(err)
	defer f.Close()
	f.Write(code.Bytes())

	fmt.Sprintf("foo: %s", code)

	var out bytes.Buffer
	cmd1 := exec.Command("g++", "-o", "main", "./build/"+"main.cpp", "./build/Builtins.cpp")
	cmd1.Stderr = &out
	err = cmd1.Run()
	if len(out.String()) != 0 {
		panic(fmt.Sprintf("error: %s", out.String()))
	}

	cmd := exec.Command("./main")
	var outb bytes.Buffer
	cmd.Stdout = &outb
	err = cmd.Run()

	if err != nil {
		panic(err.Error())
	}

	return outb.String()
}

func main() {
	if len(os.Args) < 2 {
		panic("no valid file name or path provided provided for file!")
	}

	path := os.Args[1]
	absPath, _ := filepath.Abs(path)
	input, err := ioutil.ReadFile(absPath)
	check(err)

	program := Parse(string(input))
	TypeCheck(program)
	code := gen.GenWrapper(program)
	output := Compile(code)
	fmt.Println(output)
}

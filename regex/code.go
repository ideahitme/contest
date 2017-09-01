package main

import "fmt"

func main() {
	regex := "c*a*b"
	s := "aab"

	fmt.Println(match(regex, s))
}

func match(pattern, match string) bool {
	// build the matching table

	return true
}

type state struct {
	states map[byte]*state
	val    byte
}

func (s *state) next(a byte) {

}

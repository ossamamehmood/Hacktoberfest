package main

type Stack[T comparable] []T

func (s Stack[T]) Len() int {
	return len(s)
}

func (s *Stack[T]) Push(item T) {
	*s = append(*s, item)
}

func (s *Stack[T]) Pop() *T {
	if s.Len() == 0 {
		return nil
	}

	top := (*s)[len(*s)-1]
	*s = (*s)[:len(*s)-1]
	return &top
}

func (s *Stack[T]) Peek() *T {
	if s.Len() == 0 {
		return nil
	}

	peek := (*s)[0]
	*s = (*s)[1:]
	return &peek
}

func (s *Stack[T]) IsEmpty() bool {
	return s.Len() == 0
}

var allowedPairs = map[string]string{"{": "}", "[": "]", "(": ")"}

func main() {

	snippet := "[{{[]}}]"
	stack := &Stack[string]{}
	for _, char := range snippet {
		stack.Push(string(char))
	}

	for !stack.IsEmpty() {
		pop := stack.Pop()
		peek := stack.Peek()
		if pop == nil || peek == nil || allowedPairs[*peek] != *pop {
			println("invalid code snippet")
			return
		}
	}

	println("valid code snippet")
}

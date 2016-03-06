# power_plant

[Trello Board](https://trello.com/b/T13cxD25/project-power-grid) to follow progress.

## Naming Convention

```
m for members
c for constants/readonlys
p for pointer (and pp for pointer to pointer)
v for volatile
s for static
i for indexes and iterators
e for events
g for globals

_i for integer
_f for float
_d for double
_l for long

C for classes
```

Using this convention we can easily see that the variable we are sending to Foo() is a member of MyClass and that is an Integer.

```cpp
// with naming convention
void MyClass::Foo(void) {
	Foo(m_iSomeValue)
}

// without naming convention
void CMyClass::Foo(void) {
	Foo(someValue)
	Foo(this->someValue)
}
```



### 题目汇总
#### 进程 vs 线程
1. 
    <details><summary>进程与线程有哪些区别？ 
    </summary>
    1. 111  <br/>
    2. 222  <br/>
    </details>
2. 
    <details><summary>title
    </summary>
    contents
    </details>
#### 多态
1. 
    <details><summary>在什么情况下应该使用dynamic_cast替代虚函数？</summary> 

    通常是基类设计出现问题，无法改动基类源码，又想要在派生类中添加新的成员函数，此时使用基类指针无法调用这个新的非虚函数，那就需要用dynamic_cast来进行动态类型转换从而调用到派生类的非虚函数。 
    </details>
   
2. 
    <details><summary>什么是虚函数？有什么用 
    </summary>
     一个虚函数被调用时，被执行的代码必须和调用函数的对象的动态类型相一致。虚函数是用来实现C++的动态多态的 
     </details>
3. 
    <details><summary>虚函数的实现原理 
    </summary> 
    虚函数表，虚函数指针;<br/> 
    每一个声明了虚函数或继承了虚函数的类，都会有一个自己的虚函数指针表(virtual table,vtbl) <br/> 该类的每个对象都会包含一个虚函数表指针(virtual pointer, vptr)指向vtbl，虚函数按其声明顺序放进vtbl中，vtbl中的每个元素对应一个函数指针指向该类的虚函数；如果派生类覆盖了基类的虚函数，就会放到vtbl中原来基类函数的位置。在多继承情况下每个基类都有自己的vtbl，派生类的成员函数被放到第一个基类的vtbl中 
    </details>

4. 
    <details><summary>虚函数可以是内联函数吗
    </summary>
    可以，但是当虚函数表现多态性的时候不能内联<br/>
    因为内联是建议编译器内联，而虚函数是运行时多态，编译器在编译期间无法得知运行期调用的是哪一段代码，所以运行时多态的虚函数不允许内联 <br/>
    
    </details>
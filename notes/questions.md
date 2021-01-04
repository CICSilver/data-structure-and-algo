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

5. 
    <details><summary>delete this合法吗？
    </summary>
    合法，但需要注意：<br/>
    1. 必须保证this对象时通过new（不是new[], placement new,不是栈上，不是全局，不是其他对象成员）分配的 <br/>
    2. 必须保证调用delete this的成员函数时最后一个调用this的成员 <br/>
    3. 必须保证成员函数的delete this后面没有调用this <br/>
    4. 必须保证delete this后面不会再被调用 <br/>
    </details>

6. 
    <details><summary>如何定义一个只能在堆上/栈上生成对象的类？
    </summary>
    1. 只在堆上 : <br/>
    方法：将析构函数设置为私有 <br/>
    原因：c++时静态绑定语言，编译器管理栈上对象的生命周期，编译器在为对象分配栈空间时，会先检查类的析构函数的访问性。若析构函数不可访问，则不能在栈上创建对象 <br/>
    2. 只在栈上 : <br/>
    方法：将new和delete重载为私有 <br/>
    原因：只有使用new关键词新建对象才会在堆上生成，将new私有化则无法在堆上生成对象
    </details>
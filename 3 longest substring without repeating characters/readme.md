# 算法要点

从第一个字符开始，向前遍历，
遇到一个字符，
   测试cache中存在与否，
   若是，停止本阶段，查出其索引，下一阶段从该索引往后一个字符开始；
   若否，就把它及索引储存到cache里；

```c

std::map<char, int>

```


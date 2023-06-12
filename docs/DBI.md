## Dynamic Binary Instrumentation (DBI) at runtime applications.

Common Applications:
+ Runtime profiling 
+ Profile-Guided Optimisations, 
+ Post-link optimisations (such as BOLT) 
+ Applications in security space: Dynamic analysis, deobfuscation, process sheferding

Publications
- [Instant Profiling: Instrumentation Sampling for Profiling Datacenter Applications (2013)](https://ieeexplore.ieee.org/abstract/document/6494982)

- [From Hack to Elaborate Technique—A Survey on Binary Rewriting  (2019)](https://dl.acm.org/doi/abs/10.1145/3316415)

- [Runtime-Adaptable Selective Performance Instrumentation (2023)](https://arxiv.org/abs/2303.11110)

- [An Infrastructure for Adaptive Dynamic Optimization (2003)](https://ieeexplore.ieee.org/abstract/document/1191551)

- [NVBit: A Dynamic Binary Instrumentation Framework for NVIDIA GPUs (2019)](https://dl.acm.org/doi/abs/10.1145/3352460.3358307)

- [Pin: Building customized program analysis (2019)](https://dl.acm.org/doi/abs/10.1145/3352460.3358307)

- [Valgrind: A framework for heavyweight dynamic binary instrumentation (2007)](https://dl.acm.org/doi/10.1145/1250734.1250746)

Frameworks:

- [DynamoRIO](https://dynamorio.org/) - Open source dynamic binary instrumentation framework for the development of dynamic program analysis tools. 

- [Valgrind](https://valgrind.org/) - Open source. Implements more heavy-weight instrumentation, compared to DyanmoRIO. But looks similar.

- [Pin](https://www.intel.com/content/www/us/en/developer/articles/tool/pin-a-dynamic-binary-instrumentation-tool.html) - Closed Source, Targets only Intel Platforms. Uses just-in-time compilation to perform arbitrary instrumentation tasks at user-selected points. 

- [QBDI](https://github.com/QBDI/QBDI) Quick Binary Deobfuscation and Instrumentation, Dynamic Binary Instrumentation framework based on LLVM. - Mainly used for dynamic analysis and deobfuscation, performance optimisation is not its primary domain.

- [CaPI](https://github.com/tudasc/CaPI) - Does something with LLVM XRay runtime-adaptable instrumentation and user-defined regions.

- [Instrew](https://github.com/aengelke/instrew) - LLVM-based Dynamic Binary Instrumentation

- [DynInst](https://github.com/dyninst/dyninst) - API for runtime code patching

- [VMAD](https://link.springer.com/chapter/10.1007/978-3-642-28652-0_12) - dynamic program analysis and instrumentation framework.

- [NVBit](https://research.nvidia.com/publication/2019-10_nvbit-dynamic-binary-instrumentation-framework-nvidia-gpus) - NVidia GPUs binary instrumentation framework

- Mojo, etc

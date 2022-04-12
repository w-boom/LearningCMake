#if defined(BUILD_SHARED_LIBS)
	#if define(MathFunctions_EXPORTS)
		#define MathFunctions_API __declspec(dllexport)
	#else
		#define MathFunctions_API __declspec(dllimport)
	#endif
#else
	#define MathFunctions_API
#endif


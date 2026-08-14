// C23 preprocessor additions: #warning, #elifdef, #elifndef
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
#warning "You are using C23"
#endif

#define FOO

// #elifdef / #elifndef are new in C23 (like #elif defined(...) / #elif
// !defined(...))
#if defined FOO
#define ACTIVE "FOO"
#elifdef BAR // new shortcut
#define ACTIVE "BAR"
#elifndef BAZ // new shortcut
#define ACTIVE "BAZ not defined"
#endif

#undef FOO
#undef BAR

// BAR is not defined, BAZ is not defined -> #elifndef branch
#if defined FOO
#define FALLBACK "FOO"
#elifdef BAR
#define FALLBACK "BAR"
#elifndef BAZ
#define FALLBACK "BAZ not defined"
#endif

// #warning: emits a diagnostic at compile time, but compilation continues
#ifndef VERSION
#warning "VERSION not defined, falling back to 0.1.0"
#define VERSION "0.1.0"
#endif

int main(void) {
    // Silence "unused" while proving which branches were taken
    static const char *const active = ACTIVE;
    static const char *const fallback = FALLBACK;
    static const char *const version = VERSION;

    (void)active;
    (void)fallback;
    (void)version;
    return 0;
}

//
// Created by saymon.anjos on 01/09/24.
//
#include <stdio.h>
#include <stdlib.h>
#include "compiler.h"


struct compile_process *compile_process_create(const char* filename, const char* filename_out, int flags) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return NULL;
    }

    FILE* out_file = NULL;
    if (filename_out) {
        out_file = fopen(filename_out, "w");
        if (!out_file) {
            return NULL;
        }
    }

    struct compile_process* process = calloc(1, sizeof(struct compile_process));
    process->filename = filename;
    process->cfile.fp = file;
    process->ofile = out_file;
    return process;
};

char compile_process_next_char(struct lex_process* lex_process) {
    struct compile_process* compile = lex_process->compiler;
    compile->pos.column += 1;
    const char c = getc(compile->cfile.fp);
    if (c == '\n') {
        compile->pos.line += 1;
        compile->pos.column = 1;
    }
    return c;
}

char compile_process_peek_char(struct lex_process* lex_process) {
    const struct compile_process* compiler = lex_process->compiler;
    const char c = getc(compiler->cfile.fp);
    ungetc(c, compiler->cfile.fp);
    return c;
}

char compile_process_push_char(struct lex_process* lex_process, char c) {
    const struct compile_process* compiler = lex_process->compiler;
    ungetc(c, compiler->cfile.fp);
    return c;
}

#ifndef CODE_H
#define CODE_H

typedef struct {
  int n;
  int k;
  int ** mat;
}code;

code CreerCode(int k, int n);
void LibererCode(code cc);
void AfficherCode(code cc);

#endif

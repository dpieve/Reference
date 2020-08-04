void print_segtree(VI& segtree, string s = "") {
  int siz = (int)segtree.size();
  //0
  //1, 2
  //3, 4, 5, 6
  // 7, 8, 9, 10, 11, 12, 13, 14...
  cout << "Printing seg tree " << s << endl;
  for(int i = 0; i < siz; i++) {
    cout << segtree[i] << " ";
    if(__builtin_popcount(i + 2) == 1) cout << endl;
  }
}

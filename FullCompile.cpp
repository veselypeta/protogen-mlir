/******************************
  Program "FullCompile.m" compiled by "Caching Murphi Release 5.4.9.1"

  Murphi Last Compiled date: "Oct 20 2020"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Caching Murphi Release 5.4.9.1"
#define MURPHI_DATE "Oct 20 2020"
#define PROTOCOL_NAME "FullCompile"
#define BITS_IN_WORLD 6672
#define ALIGN

/********************
  Include
 ********************/
#include "mu_prolog.hpp"

/********************
  Decl declaration
 ********************/

class mu_1_Access: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Access& val) { return value(val.value()); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Access& val)
  {
    if (val.defined())
      return ( s << mu_1_Access::values[ int(val) - 1] );
    else return ( s << "Undefined" );
  };

  mu_1_Access (const char *name, int os): mu__byte(1, 3, 2, name, os) {};
  mu_1_Access (void): mu__byte(1, 3, 2) {};
  mu_1_Access (int val): mu__byte(1, 3, 2, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  const char * Name() { return values[ value() -1]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -1] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

const char *mu_1_Access::values[] = {"load","store","none",NULL };

/*** end of enum declaration ***/
mu_1_Access mu_1_Access_undefined_var;

class mu_1_MessageType: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_MessageType& val) { return value(val.value()); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_MessageType& val)
  {
    if (val.defined())
      return ( s << mu_1_MessageType::values[ int(val) - 4] );
    else return ( s << "Undefined" );
  };

  mu_1_MessageType (const char *name, int os): mu__byte(4, 8, 3, name, os) {};
  mu_1_MessageType (void): mu__byte(4, 8, 3) {};
  mu_1_MessageType (int val): mu__byte(4, 8, 3, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  const char * Name() { return values[ value() -4]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -4] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

const char *mu_1_MessageType::values[] = {"Fwd_GetM","GetM","GetM_Ack_D","PutM","Put_Ack",NULL };

/*** end of enum declaration ***/
mu_1_MessageType mu_1_MessageType_undefined_var;

class mu_1_cache_state: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_cache_state& val) { return value(val.value()); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_cache_state& val)
  {
    if (val.defined())
      return ( s << mu_1_cache_state::values[ int(val) - 9] );
    else return ( s << "Undefined" );
  };

  mu_1_cache_state (const char *name, int os): mu__byte(9, 13, 3, name, os) {};
  mu_1_cache_state (void): mu__byte(9, 13, 3) {};
  mu_1_cache_state (int val): mu__byte(9, 13, 3, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  const char * Name() { return values[ value() -9]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -9] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

const char *mu_1_cache_state::values[] = {"cache_I","cache_I_load","cache_I_store","cache_M","cache_M_evict",NULL };

/*** end of enum declaration ***/
mu_1_cache_state mu_1_cache_state_undefined_var;

class mu_1_directory_state: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_directory_state& val) { return value(val.value()); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_directory_state& val)
  {
    if (val.defined())
      return ( s << mu_1_directory_state::values[ int(val) - 14] );
    else return ( s << "Undefined" );
  };

  mu_1_directory_state (const char *name, int os): mu__byte(14, 15, 2, name, os) {};
  mu_1_directory_state (void): mu__byte(14, 15, 2) {};
  mu_1_directory_state (int val): mu__byte(14, 15, 2, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  const char * Name() { return values[ value() -14]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -14] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

const char *mu_1_directory_state::values[] = {"directory_I","directory_M",NULL };

/*** end of enum declaration ***/
mu_1_directory_state mu_1_directory_state_undefined_var;

class mu_1_Address: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Address& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Address& val)
    {
      if (val.defined())
	return ( s << mu_1_Address::values[ int(val) - 16 ] );
      else
	return ( s << "Undefined" );
    };

  mu_1_Address (const char *name, int os): mu__byte(16, 16, 1, name, os) {};
  mu_1_Address (void): mu__byte(16, 16, 1) {};
  mu_1_Address (int val): mu__byte(16, 16, 1, "Parameter or function result.", 0)
    { operator=(val); };
  const char * Name() { return values[ value() -16]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 16] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_Address& a, mu_1_Address& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
};
const char *mu_1_Address::values[] =
  { "Address_1",NULL };

/*** end scalarset declaration ***/
mu_1_Address mu_1_Address_undefined_var;

class mu_1_ClValue: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_ClValue& val) { return mu__byte::operator=((int) val); };
  mu_1_ClValue (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1_ClValue (void): mu__byte(0, 1, 2) {};
  mu_1_ClValue (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_ClValue mu_1_ClValue_undefined_var;

class mu_1_OBJSET_cache: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_OBJSET_cache& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_OBJSET_cache& val)
    {
      if (val.defined())
	return ( s << mu_1_OBJSET_cache::values[ int(val) - 17 ] );
      else
	return ( s << "Undefined" );
    };

  mu_1_OBJSET_cache (const char *name, int os): mu__byte(17, 19, 2, name, os) {};
  mu_1_OBJSET_cache (void): mu__byte(17, 19, 2) {};
  mu_1_OBJSET_cache (int val): mu__byte(17, 19, 2, "Parameter or function result.", 0)
    { operator=(val); };
  const char * Name() { return values[ value() -17]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 17] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_OBJSET_cache& a, mu_1_OBJSET_cache& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
};
const char *mu_1_OBJSET_cache::values[] =
  { "OBJSET_cache_1","OBJSET_cache_2","OBJSET_cache_3",NULL };

/*** end scalarset declaration ***/
mu_1_OBJSET_cache mu_1_OBJSET_cache_undefined_var;

class mu_1_OBJSET_directory: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_OBJSET_directory& val) { return value(val.value()); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_OBJSET_directory& val)
  {
    if (val.defined())
      return ( s << mu_1_OBJSET_directory::values[ int(val) - 20] );
    else return ( s << "Undefined" );
  };

  mu_1_OBJSET_directory (const char *name, int os): mu__byte(20, 20, 1, name, os) {};
  mu_1_OBJSET_directory (void): mu__byte(20, 20, 1) {};
  mu_1_OBJSET_directory (int val): mu__byte(20, 20, 1, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  const char * Name() { return values[ value() -20]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -20] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

const char *mu_1_OBJSET_directory::values[] = {"directory",NULL };

/*** end of enum declaration ***/
mu_1_OBJSET_directory mu_1_OBJSET_directory_undefined_var;

class mu_1_Machines: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Machines& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Machines& val)
    {
      if (val.defined())
	return ( s << mu_1_Machines::values[ val.indexvalue() ] );
      else
	return ( s << "Undefined" );
    };

  // note thate lb and ub are not used if we have byte compacted state.
  mu_1_Machines (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1_Machines (void): mu__byte(0, 3, 3) {};
  mu_1_Machines (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
    { operator=(val); };
  int indexvalue()
  {
    if ((value() >= 17) && (value() <= 19)) return (value() - 17);
    if ((value() >= 20) && (value() <= 20)) return (value() - 17);
  return 0;
  };
  inline int unionassign(int val)
  {
    if (val >= 0 && val <= 2) return value(val+17);
    if (val >= 3 && val <= 3) return value(val+17);
  return 0;
  };
  const char * Name() { return values[ indexvalue() ]; };
friend int CompareWeight(mu_1_Machines& a, mu_1_Machines& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ indexvalue() ] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
};
const char *mu_1_Machines::values[] = {"OBJSET_cache_1","OBJSET_cache_2","OBJSET_cache_3","directory",NULL };

/*** end union declaration ***/
mu_1_Machines mu_1_Machines_undefined_var;

class mu_1_ENTRY_cache
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1_cache_state mu_State;
  mu_1_ClValue mu_cl;
  mu_1_Access mu_Perm;
  mu_1_ENTRY_cache ( const char *n, int os ) { set_self(n,os); };
  mu_1_ENTRY_cache ( void ) {};

  virtual ~mu_1_ENTRY_cache(); 
friend int CompareWeight(mu_1_ENTRY_cache& a, mu_1_ENTRY_cache& b)
  {
    int w;
    w = CompareWeight(a.mu_State, b.mu_State);
    if (w!=0) return w;
    w = CompareWeight(a.mu_cl, b.mu_cl);
    if (w!=0) return w;
    w = CompareWeight(a.mu_Perm, b.mu_Perm);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_ENTRY_cache& a, mu_1_ENTRY_cache& b)
  {
    int w;
    w = Compare(a.mu_State, b.mu_State);
    if (w!=0) return w;
    w = Compare(a.mu_cl, b.mu_cl);
    if (w!=0) return w;
    w = Compare(a.mu_Perm, b.mu_Perm);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_State.MultisetSort();
    mu_cl.MultisetSort();
    mu_Perm.MultisetSort();
  }
  void print_statistic()
  {
    mu_State.print_statistic();
    mu_cl.print_statistic();
    mu_Perm.print_statistic();
  }
  void clear() {
    mu_State.clear();
    mu_cl.clear();
    mu_Perm.clear();
 };
  void undefine() {
    mu_State.undefine();
    mu_cl.undefine();
    mu_Perm.undefine();
 };
  void reset() {
    mu_State.reset();
    mu_cl.reset();
    mu_Perm.reset();
 };
  void print() {
    mu_State.print();
    mu_cl.print();
    mu_Perm.print();
  };
  void print_diff(state *prevstate) {
    mu_State.print_diff(prevstate);
    mu_cl.print_diff(prevstate);
    mu_Perm.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_State.to_state(thestate);
    mu_cl.to_state(thestate);
    mu_Perm.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_ENTRY_cache& operator= (const mu_1_ENTRY_cache& from) {
    mu_State.value(from.mu_State.value());
    mu_cl.value(from.mu_cl.value());
    mu_Perm.value(from.mu_Perm.value());
    return *this;
  };
};

  void mu_1_ENTRY_cache::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_ENTRY_cache::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_ENTRY_cache::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_State.set_self_2(name, ".State", os + 0 ); else mu_State.set_self_2(NULL, NULL, 0);
  if (name) mu_cl.set_self_2(name, ".cl", os + 8 ); else mu_cl.set_self_2(NULL, NULL, 0);
  if (name) mu_Perm.set_self_2(name, ".Perm", os + 16 ); else mu_Perm.set_self_2(NULL, NULL, 0);
}

mu_1_ENTRY_cache::~mu_1_ENTRY_cache()
{
}

/*** end record declaration ***/
mu_1_ENTRY_cache mu_1_ENTRY_cache_undefined_var;

class mu_1_ENTRY_directory
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1_directory_state mu_State;
  mu_1_ClValue mu_cl;
  mu_1_Machines mu_owner;
  mu_1_Access mu_Perm;
  mu_1_ENTRY_directory ( const char *n, int os ) { set_self(n,os); };
  mu_1_ENTRY_directory ( void ) {};

  virtual ~mu_1_ENTRY_directory(); 
friend int CompareWeight(mu_1_ENTRY_directory& a, mu_1_ENTRY_directory& b)
  {
    int w;
    w = CompareWeight(a.mu_State, b.mu_State);
    if (w!=0) return w;
    w = CompareWeight(a.mu_cl, b.mu_cl);
    if (w!=0) return w;
    w = CompareWeight(a.mu_owner, b.mu_owner);
    if (w!=0) return w;
    w = CompareWeight(a.mu_Perm, b.mu_Perm);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_ENTRY_directory& a, mu_1_ENTRY_directory& b)
  {
    int w;
    w = Compare(a.mu_State, b.mu_State);
    if (w!=0) return w;
    w = Compare(a.mu_cl, b.mu_cl);
    if (w!=0) return w;
    w = Compare(a.mu_owner, b.mu_owner);
    if (w!=0) return w;
    w = Compare(a.mu_Perm, b.mu_Perm);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_State.MultisetSort();
    mu_cl.MultisetSort();
    mu_owner.MultisetSort();
    mu_Perm.MultisetSort();
  }
  void print_statistic()
  {
    mu_State.print_statistic();
    mu_cl.print_statistic();
    mu_owner.print_statistic();
    mu_Perm.print_statistic();
  }
  void clear() {
    mu_State.clear();
    mu_cl.clear();
    mu_owner.clear();
    mu_Perm.clear();
 };
  void undefine() {
    mu_State.undefine();
    mu_cl.undefine();
    mu_owner.undefine();
    mu_Perm.undefine();
 };
  void reset() {
    mu_State.reset();
    mu_cl.reset();
    mu_owner.reset();
    mu_Perm.reset();
 };
  void print() {
    mu_State.print();
    mu_cl.print();
    mu_owner.print();
    mu_Perm.print();
  };
  void print_diff(state *prevstate) {
    mu_State.print_diff(prevstate);
    mu_cl.print_diff(prevstate);
    mu_owner.print_diff(prevstate);
    mu_Perm.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_State.to_state(thestate);
    mu_cl.to_state(thestate);
    mu_owner.to_state(thestate);
    mu_Perm.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_ENTRY_directory& operator= (const mu_1_ENTRY_directory& from) {
    mu_State.value(from.mu_State.value());
    mu_cl.value(from.mu_cl.value());
    mu_owner.value(from.mu_owner.value());
    mu_Perm.value(from.mu_Perm.value());
    return *this;
  };
};

  void mu_1_ENTRY_directory::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_ENTRY_directory::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_ENTRY_directory::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_State.set_self_2(name, ".State", os + 0 ); else mu_State.set_self_2(NULL, NULL, 0);
  if (name) mu_cl.set_self_2(name, ".cl", os + 8 ); else mu_cl.set_self_2(NULL, NULL, 0);
  if (name) mu_owner.set_self_2(name, ".owner", os + 16 ); else mu_owner.set_self_2(NULL, NULL, 0);
  if (name) mu_Perm.set_self_2(name, ".Perm", os + 24 ); else mu_Perm.set_self_2(NULL, NULL, 0);
}

mu_1_ENTRY_directory::~mu_1_ENTRY_directory()
{
}

/*** end record declaration ***/
mu_1_ENTRY_directory mu_1_ENTRY_directory_undefined_var;

class mu_1_Message
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1_Address mu_adr;
  mu_1_MessageType mu_mtype;
  mu_1_Machines mu_src;
  mu_1_Machines mu_dst;
  mu_1_ClValue mu_cl;
  mu_1_Message ( const char *n, int os ) { set_self(n,os); };
  mu_1_Message ( void ) {};

  virtual ~mu_1_Message(); 
friend int CompareWeight(mu_1_Message& a, mu_1_Message& b)
  {
    int w;
    w = CompareWeight(a.mu_adr, b.mu_adr);
    if (w!=0) return w;
    w = CompareWeight(a.mu_mtype, b.mu_mtype);
    if (w!=0) return w;
    w = CompareWeight(a.mu_src, b.mu_src);
    if (w!=0) return w;
    w = CompareWeight(a.mu_dst, b.mu_dst);
    if (w!=0) return w;
    w = CompareWeight(a.mu_cl, b.mu_cl);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_Message& a, mu_1_Message& b)
  {
    int w;
    w = Compare(a.mu_adr, b.mu_adr);
    if (w!=0) return w;
    w = Compare(a.mu_mtype, b.mu_mtype);
    if (w!=0) return w;
    w = Compare(a.mu_src, b.mu_src);
    if (w!=0) return w;
    w = Compare(a.mu_dst, b.mu_dst);
    if (w!=0) return w;
    w = Compare(a.mu_cl, b.mu_cl);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_adr.MultisetSort();
    mu_mtype.MultisetSort();
    mu_src.MultisetSort();
    mu_dst.MultisetSort();
    mu_cl.MultisetSort();
  }
  void print_statistic()
  {
    mu_adr.print_statistic();
    mu_mtype.print_statistic();
    mu_src.print_statistic();
    mu_dst.print_statistic();
    mu_cl.print_statistic();
  }
  void clear() {
    mu_adr.clear();
    mu_mtype.clear();
    mu_src.clear();
    mu_dst.clear();
    mu_cl.clear();
 };
  void undefine() {
    mu_adr.undefine();
    mu_mtype.undefine();
    mu_src.undefine();
    mu_dst.undefine();
    mu_cl.undefine();
 };
  void reset() {
    mu_adr.reset();
    mu_mtype.reset();
    mu_src.reset();
    mu_dst.reset();
    mu_cl.reset();
 };
  void print() {
    mu_adr.print();
    mu_mtype.print();
    mu_src.print();
    mu_dst.print();
    mu_cl.print();
  };
  void print_diff(state *prevstate) {
    mu_adr.print_diff(prevstate);
    mu_mtype.print_diff(prevstate);
    mu_src.print_diff(prevstate);
    mu_dst.print_diff(prevstate);
    mu_cl.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_adr.to_state(thestate);
    mu_mtype.to_state(thestate);
    mu_src.to_state(thestate);
    mu_dst.to_state(thestate);
    mu_cl.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_Message& operator= (const mu_1_Message& from) {
    mu_adr.value(from.mu_adr.value());
    mu_mtype.value(from.mu_mtype.value());
    mu_src.value(from.mu_src.value());
    mu_dst.value(from.mu_dst.value());
    mu_cl.value(from.mu_cl.value());
    return *this;
  };
};

  void mu_1_Message::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_Message::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_Message::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_adr.set_self_2(name, ".adr", os + 0 ); else mu_adr.set_self_2(NULL, NULL, 0);
  if (name) mu_mtype.set_self_2(name, ".mtype", os + 8 ); else mu_mtype.set_self_2(NULL, NULL, 0);
  if (name) mu_src.set_self_2(name, ".src", os + 16 ); else mu_src.set_self_2(NULL, NULL, 0);
  if (name) mu_dst.set_self_2(name, ".dst", os + 24 ); else mu_dst.set_self_2(NULL, NULL, 0);
  if (name) mu_cl.set_self_2(name, ".cl", os + 32 ); else mu_cl.set_self_2(NULL, NULL, 0);
}

mu_1_Message::~mu_1_Message()
{
}

/*** end record declaration ***/
mu_1_Message mu_1_Message_undefined_var;

class mu_1__type_0
{
 public:
  mu_1_ENTRY_cache array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_0 (const char *n, int os) { set_self(n, os); };
  mu_1__type_0 ( void ) {};
  virtual ~mu_1__type_0 ();
  mu_1_ENTRY_cache& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 16 ) && ( index <= 16 ) )
      return array[ index - 16 ];
    else
      {
	if (index==UNDEFVAL) 
	  Error.Error("Indexing to %s using an undefined value.", name);
	else
	  Error.Error("Funny index value %d for %s: Address is internally represented from 16 to 16.\nInternal Error in Type checking.",index, name);
	return array[0];
      }
#else
    return array[ index - 16 ];
#endif
  };
  mu_1__type_0& operator= (const mu_1__type_0& from)
  {
      array[0] = from.array[0];
    return *this;
  }

friend int CompareWeight(mu_1__type_0& a, mu_1__type_0& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_0& a, mu_1__type_0& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 1; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_0::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_0::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_0::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"Address_1", i * 24 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
}
mu_1__type_0::~mu_1__type_0()
{
}
/*** end array declaration ***/
mu_1__type_0 mu_1__type_0_undefined_var;

class mu_1_MACH_cache
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1__type_0 mu_CL;
  mu_1_MACH_cache ( const char *n, int os ) { set_self(n,os); };
  mu_1_MACH_cache ( void ) {};

  virtual ~mu_1_MACH_cache(); 
friend int CompareWeight(mu_1_MACH_cache& a, mu_1_MACH_cache& b)
  {
    int w;
    w = CompareWeight(a.mu_CL, b.mu_CL);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_MACH_cache& a, mu_1_MACH_cache& b)
  {
    int w;
    w = Compare(a.mu_CL, b.mu_CL);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_CL.MultisetSort();
  }
  void print_statistic()
  {
    mu_CL.print_statistic();
  }
  void clear() {
    mu_CL.clear();
 };
  void undefine() {
    mu_CL.undefine();
 };
  void reset() {
    mu_CL.reset();
 };
  void print() {
    mu_CL.print();
  };
  void print_diff(state *prevstate) {
    mu_CL.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_CL.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_MACH_cache& operator= (const mu_1_MACH_cache& from) {
    mu_CL = from.mu_CL;
    return *this;
  };
};

  void mu_1_MACH_cache::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_MACH_cache::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_MACH_cache::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_CL.set_self_2(name, ".CL", os + 0 ); else mu_CL.set_self_2(NULL, NULL, 0);
}

mu_1_MACH_cache::~mu_1_MACH_cache()
{
}

/*** end record declaration ***/
mu_1_MACH_cache mu_1_MACH_cache_undefined_var;

class mu_1__type_1
{
 public:
  mu_1_ENTRY_directory array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_1 (const char *n, int os) { set_self(n, os); };
  mu_1__type_1 ( void ) {};
  virtual ~mu_1__type_1 ();
  mu_1_ENTRY_directory& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 16 ) && ( index <= 16 ) )
      return array[ index - 16 ];
    else
      {
	if (index==UNDEFVAL) 
	  Error.Error("Indexing to %s using an undefined value.", name);
	else
	  Error.Error("Funny index value %d for %s: Address is internally represented from 16 to 16.\nInternal Error in Type checking.",index, name);
	return array[0];
      }
#else
    return array[ index - 16 ];
#endif
  };
  mu_1__type_1& operator= (const mu_1__type_1& from)
  {
      array[0] = from.array[0];
    return *this;
  }

friend int CompareWeight(mu_1__type_1& a, mu_1__type_1& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_1& a, mu_1__type_1& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 1; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_1::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_1::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_1::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"Address_1", i * 32 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
}
mu_1__type_1::~mu_1__type_1()
{
}
/*** end array declaration ***/
mu_1__type_1 mu_1__type_1_undefined_var;

class mu_1_MACH_directory
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1__type_1 mu_CL;
  mu_1_MACH_directory ( const char *n, int os ) { set_self(n,os); };
  mu_1_MACH_directory ( void ) {};

  virtual ~mu_1_MACH_directory(); 
friend int CompareWeight(mu_1_MACH_directory& a, mu_1_MACH_directory& b)
  {
    int w;
    w = CompareWeight(a.mu_CL, b.mu_CL);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_MACH_directory& a, mu_1_MACH_directory& b)
  {
    int w;
    w = Compare(a.mu_CL, b.mu_CL);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_CL.MultisetSort();
  }
  void print_statistic()
  {
    mu_CL.print_statistic();
  }
  void clear() {
    mu_CL.clear();
 };
  void undefine() {
    mu_CL.undefine();
 };
  void reset() {
    mu_CL.reset();
 };
  void print() {
    mu_CL.print();
  };
  void print_diff(state *prevstate) {
    mu_CL.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_CL.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_MACH_directory& operator= (const mu_1_MACH_directory& from) {
    mu_CL = from.mu_CL;
    return *this;
  };
};

  void mu_1_MACH_directory::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_MACH_directory::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_MACH_directory::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_CL.set_self_2(name, ".CL", os + 0 ); else mu_CL.set_self_2(NULL, NULL, 0);
}

mu_1_MACH_directory::~mu_1_MACH_directory()
{
}

/*** end record declaration ***/
mu_1_MACH_directory mu_1_MACH_directory_undefined_var;

class mu_1_OBJ_cache
{
 public:
  mu_1_MACH_cache array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1_OBJ_cache (const char *n, int os) { set_self(n, os); };
  mu_1_OBJ_cache ( void ) {};
  virtual ~mu_1_OBJ_cache ();
  mu_1_MACH_cache& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 17 ) && ( index <= 19 ) )
      return array[ index - 17 ];
    else
      {
	if (index==UNDEFVAL) 
	  Error.Error("Indexing to %s using an undefined value.", name);
	else
	  Error.Error("Funny index value %d for %s: OBJSET_cache is internally represented from 17 to 19.\nInternal Error in Type checking.",index, name);
	return array[0];
      }
#else
    return array[ index - 17 ];
#endif
  };
  mu_1_OBJ_cache& operator= (const mu_1_OBJ_cache& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1_OBJ_cache& a, mu_1_OBJ_cache& b)
  {
    return 0;
  }
friend int Compare(mu_1_OBJ_cache& a, mu_1_OBJ_cache& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1_OBJ_cache::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_OBJ_cache::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_OBJ_cache::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"OBJSET_cache_1", i * 24 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"OBJSET_cache_2", i * 24 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"OBJSET_cache_3", i * 24 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
}
mu_1_OBJ_cache::~mu_1_OBJ_cache()
{
}
/*** end array declaration ***/
mu_1_OBJ_cache mu_1_OBJ_cache_undefined_var;

class mu_1_OBJ_directory
{
 public:
  mu_1_MACH_directory array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1_OBJ_directory (const char *n, int os) { set_self(n, os); };
  mu_1_OBJ_directory ( void ) {};
  virtual ~mu_1_OBJ_directory ();
  mu_1_MACH_directory& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 20 ) && ( index <= 20 ) )
      return array[ index - 20 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 20 ];
#endif
  };
  mu_1_OBJ_directory& operator= (const mu_1_OBJ_directory& from)
  {
      array[0] = from.array[0];
    return *this;
  }

friend int CompareWeight(mu_1_OBJ_directory& a, mu_1_OBJ_directory& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1_OBJ_directory& a, mu_1_OBJ_directory& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 1; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1_OBJ_directory::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_OBJ_directory::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
  void mu_1_OBJ_directory::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"directory", i * 32 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
  }
mu_1_OBJ_directory::~mu_1_OBJ_directory()
{
}
/*** end array declaration ***/
mu_1_OBJ_directory mu_1_OBJ_directory_undefined_var;

class mu__subrange_21: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_21& val) { return mu__byte::operator=((int) val); };
  mu__subrange_21 (const char *name, int os): mu__byte(0, 11, 4, name, os) {};
  mu__subrange_21 (void): mu__byte(0, 11, 4) {};
  mu__subrange_21 (int val): mu__byte(0, 11, 4, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_21 mu__subrange_21_undefined_var;

class mu_1__type_2
{
 public:
  mu_1_Message array[ 12 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_2 (const char *n, int os) { set_self(n, os); };
  mu_1__type_2 ( void ) {};
  virtual ~mu_1__type_2 ();
  mu_1_Message& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 11 ) )
      return array[ index - 0 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 0 ];
#endif
  };
  mu_1__type_2& operator= (const mu_1__type_2& from)
  {
    for (int i = 0; i < 12; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_2& a, mu_1__type_2& b)
  {
    int w;
    for (int i=0; i<12; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_2& a, mu_1__type_2& b)
  {
    int w;
    for (int i=0; i<12; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<12; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<12; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 12; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 12; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 12; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 12; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 12; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 12; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_2::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_2::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_2::set_self( const char *n, int os)
{
  char* s;
  name = (char *)n;
  for(int i = 0; i < 12; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 40 + os);
    delete[] s;
  }
};
mu_1__type_2::~mu_1__type_2()
{
}
/*** end array declaration ***/
mu_1__type_2 mu_1__type_2_undefined_var;

class mu_1_OBJ_Ordered
{
 public:
  mu_1__type_2 array[ 4 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1_OBJ_Ordered (const char *n, int os) { set_self(n, os); };
  mu_1_OBJ_Ordered ( void ) {};
  virtual ~mu_1_OBJ_Ordered ();
  mu_1__type_2& operator[] (int index) /* const */
  {
    if ( ( index >= 17 ) && ( index <= 19 ) )
      return array[ index - (17) ];
    if ( ( index >= 20 ) && ( index <= 20 ) )
      return array[ index - (17) ];
    if (index==UNDEFVAL) 
      Error.Error("Indexing to %s using an undefined value.", name);
    else
      Error.Error("Funny index value %d for %s. (Internal Error in Type Checking.",index, name);
    return array[0];
  }
  mu_1_OBJ_Ordered& operator= (const mu_1_OBJ_Ordered& from)
  {
    for (int i = 0; i < 4; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1_OBJ_Ordered& a, mu_1_OBJ_Ordered& b)
  {
    return 0;
  }
friend int Compare(mu_1_OBJ_Ordered& a, mu_1_OBJ_Ordered& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<4; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<4; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 4; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 4; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 4; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 4; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 4; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 4; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1_OBJ_Ordered::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_OBJ_Ordered::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_OBJ_Ordered::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"OBJSET_cache_1", i * 480 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"OBJSET_cache_2", i * 480 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"OBJSET_cache_3", i * 480 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"directory", i * 480 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
}
mu_1_OBJ_Ordered::~mu_1_OBJ_Ordered()
{
}
/*** end array declaration ***/
mu_1_OBJ_Ordered mu_1_OBJ_Ordered_undefined_var;

class mu_1__type_3: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_3& val) { return mu__byte::operator=((int) val); };
  mu_1__type_3 (const char *name, int os): mu__byte(0, 12, 4, name, os) {};
  mu_1__type_3 (void): mu__byte(0, 12, 4) {};
  mu_1__type_3 (int val): mu__byte(0, 12, 4, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_3 mu_1__type_3_undefined_var;

class mu_1_OBJ_Orderedcnt
{
 public:
  mu_1__type_3 array[ 4 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1_OBJ_Orderedcnt (const char *n, int os) { set_self(n, os); };
  mu_1_OBJ_Orderedcnt ( void ) {};
  virtual ~mu_1_OBJ_Orderedcnt ();
  mu_1__type_3& operator[] (int index) /* const */
  {
    if ( ( index >= 17 ) && ( index <= 19 ) )
      return array[ index - (17) ];
    if ( ( index >= 20 ) && ( index <= 20 ) )
      return array[ index - (17) ];
    if (index==UNDEFVAL) 
      Error.Error("Indexing to %s using an undefined value.", name);
    else
      Error.Error("Funny index value %d for %s. (Internal Error in Type Checking.",index, name);
    return array[0];
  }
  mu_1_OBJ_Orderedcnt& operator= (const mu_1_OBJ_Orderedcnt& from)
  {
    for (int i = 0; i < 4; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1_OBJ_Orderedcnt& a, mu_1_OBJ_Orderedcnt& b)
  {
    return 0;
  }
friend int Compare(mu_1_OBJ_Orderedcnt& a, mu_1_OBJ_Orderedcnt& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<4; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<4; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 4; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 4; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 4; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 4; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 4; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 4; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1_OBJ_Orderedcnt::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_OBJ_Orderedcnt::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_OBJ_Orderedcnt::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"OBJSET_cache_1", i * 8 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"OBJSET_cache_2", i * 8 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"OBJSET_cache_3", i * 8 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"directory", i * 8 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
}
mu_1_OBJ_Orderedcnt::~mu_1_OBJ_Orderedcnt()
{
}
/*** end array declaration ***/
mu_1_OBJ_Orderedcnt mu_1_OBJ_Orderedcnt_undefined_var;

/*** begin multiset declaration ***/
class mu_1__type_4_id: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_4_id& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  mu_1__type_4_id () : mu__byte(0,11,0) {};
  mu_1__type_4_id (int val) : mu__byte(0,11,0, "Parameter or function result.",0) {operator=(val); };
  char * Name() { return tsprintf("%d", value()); };
};
class mu_1__type_4
{
 public:
  mu_1_Message array[ 12 ];
  int max_size;
  int current_size;
 public:
  mu_0_boolean valid[ 12 ];
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_4 (const char *n, int os): current_size(0), max_size(0) { set_self(n, os); };
  mu_1__type_4 ( void ): current_size(0), max_size(0) {};
  virtual ~mu_1__type_4 ();
  mu_1_Message& operator[] (int index) /* const */
  {
    if ((index >= 0) && (index <= 11) && valid[index].value())
      return array[ index ];
    else {
      Error.Error("Internal Error::%d not in index range of %s.", index, name);
      return array[0];
    }
  };
  mu_1__type_4& operator= (const mu_1__type_4& from)
  {
    for (int i = 0; i < 12; i++)
    {
       array[i] = from.array[i];
       valid[i].value(from.valid[i].value());
    };
    current_size = from.get_current_size();
    return *this;
  }

friend int CompareWeight(mu_1__type_4& a, mu_1__type_4& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_4& a, mu_1__type_4& b)
  {
    int w;
    for (int i=0; i<12; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  void clear() { for (int i = 0; i < 12; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void undefine() { for (int i = 0; i < 12; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void reset() { for (int i = 0; i < 12; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 12; i++)
     {
       array[i].to_state(thestate);
       valid[i].to_state(thestate);
     }
  };

  int get_current_size() const  {
    int tmp = 0;
    for (int i = 0; i < 12; i++)
      if (valid[i].value()) tmp++;
    return tmp;
  };

   void update_size()
  {
    current_size = 0;
    for (int i = 0; i < 12; i++)
      if (valid[i].value()) current_size++;
    if (max_size<current_size) max_size = current_size;
  };

   inline bool in(const mu_1__type_4_id& id)
  { return valid[(int)id].value(); }
  void print()
  {
    for (int i = 0; i < 12; i++)
      if (valid[i].value())
	array[i].print();
  };

  void print_statistic()
  {
    cout << "	The maximum size for the multiset \"" 
	 << name << "\" is: " << max_size << ".\n"; 
  };
  void print_diff(state *prevstate)
  {
    bool prevvalid;
    static state temp;
    StateCopy(&temp, workingstate);
    for (int i = 0; i < 12; i++)
      {
	StateCopy(workingstate, prevstate);
	prevvalid = valid[i].value();
	StateCopy(workingstate, &temp);
	if (prevvalid && !valid[i].value())
	  array[i].print();
	if (!prevvalid && valid[i].value())
	  array[i].print();
	if (prevvalid && valid[i].value())
	  array[i].print_diff(prevstate);
      }
  };
  int multisetadd(const mu_1_Message &element)
  {
    update_size();
    if (current_size >= 12) Error.Error("Maximum size of MultiSet (%s) exceeded.",name);
    int i;
    for (i = 0; i < 12; i++)
      if (!valid[i].value())
	{
	  array[i] = element;
	  valid[i].value(TRUE);
	  break;
	}
    current_size++;
    return i;
  };
  void multisetremove(const mu_1__type_4_id &id)
  {
    update_size();
    if (!valid[(int)id].value()) Error.Error("Internal Error: Illegal Multiset element selected.");
    valid[(int)id].value(FALSE);
    array[(int)id].undefine();
    current_size--;
  };
  void MultisetSort()
  {
    static mu_1_Message temp;

    // compact
    int i,j;
    for (i = 0, j = 0; i < 12; i++)
      if (valid[i].value())
	{
	  if (j!=i)
	    array[j++] = array[i];
	  else
	    j++;
	}
    if (j != current_size) current_size = j;
    for (i = j; i < 12; i++)
      array[i].undefine();
    for (i = 0; i < j; i++)
      valid[i].value(TRUE);
    for (i = j; i < 12; i++)
      valid[i].value(FALSE);

    // bubble sort
    for (i = 0; i < current_size; i++)
      for (j = i+1; j < current_size; j++)
	if (Compare(array[i],array[j])>0)
	  {
	    temp = array[i];
	    array[i] = array[j];
	    array[j] = temp;
	  }
  }
};

  void mu_1__type_4::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_4::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_4::set_self( const char *n, int os)
{
  int i,k;
  name = (char *)n;
  for(i = 0; i < 12; i++)
    if (n) array[i].set_self(tsprintf("%s{%d}", n,i), i * 40 + os); else array[i].set_self(NULL, 0);
  k = os + i * 40;
  for(i = 0; i < 12; i++)
    valid[i].set_self("", i * 8 + k);
};
mu_1__type_4::~mu_1__type_4()
{
}
/*** end multiset declaration ***/
mu_1__type_4 mu_1__type_4_undefined_var;

class mu_1_OBJ_Unordered
{
 public:
  mu_1__type_4 array[ 4 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1_OBJ_Unordered (const char *n, int os) { set_self(n, os); };
  mu_1_OBJ_Unordered ( void ) {};
  virtual ~mu_1_OBJ_Unordered ();
  mu_1__type_4& operator[] (int index) /* const */
  {
    if ( ( index >= 17 ) && ( index <= 19 ) )
      return array[ index - (17) ];
    if ( ( index >= 20 ) && ( index <= 20 ) )
      return array[ index - (17) ];
    if (index==UNDEFVAL) 
      Error.Error("Indexing to %s using an undefined value.", name);
    else
      Error.Error("Funny index value %d for %s. (Internal Error in Type Checking.",index, name);
    return array[0];
  }
  mu_1_OBJ_Unordered& operator= (const mu_1_OBJ_Unordered& from)
  {
    for (int i = 0; i < 4; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1_OBJ_Unordered& a, mu_1_OBJ_Unordered& b)
  {
    return 0;
  }
friend int Compare(mu_1_OBJ_Unordered& a, mu_1_OBJ_Unordered& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<4; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<4; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 4; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 4; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 4; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 4; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 4; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 4; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1_OBJ_Unordered::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_OBJ_Unordered::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_OBJ_Unordered::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"OBJSET_cache_1", i * 576 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"OBJSET_cache_2", i * 576 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"OBJSET_cache_3", i * 576 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"directory", i * 576 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
}
mu_1_OBJ_Unordered::~mu_1_OBJ_Unordered()
{
}
/*** end array declaration ***/
mu_1_OBJ_Unordered mu_1_OBJ_Unordered_undefined_var;

class mu_1_CL_MUTEX
{
 public:
  mu_0_boolean array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1_CL_MUTEX (const char *n, int os) { set_self(n, os); };
  mu_1_CL_MUTEX ( void ) {};
  virtual ~mu_1_CL_MUTEX ();
  mu_0_boolean& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 16 ) && ( index <= 16 ) )
      return array[ index - 16 ];
    else
      {
	if (index==UNDEFVAL) 
	  Error.Error("Indexing to %s using an undefined value.", name);
	else
	  Error.Error("Funny index value %d for %s: Address is internally represented from 16 to 16.\nInternal Error in Type checking.",index, name);
	return array[0];
      }
#else
    return array[ index - 16 ];
#endif
  };
  mu_1_CL_MUTEX& operator= (const mu_1_CL_MUTEX& from)
  {
      array[0].value(from.array[0].value());
    return *this;
  }

friend int CompareWeight(mu_1_CL_MUTEX& a, mu_1_CL_MUTEX& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1_CL_MUTEX& a, mu_1_CL_MUTEX& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 1; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1_CL_MUTEX::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_CL_MUTEX::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_CL_MUTEX::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"Address_1", i * 8 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
}
mu_1_CL_MUTEX::~mu_1_CL_MUTEX()
{
}
/*** end array declaration ***/
mu_1_CL_MUTEX mu_1_CL_MUTEX_undefined_var;

const int mu_NrCaches = 3;
const int mu_VAL_COUNT = 1;
const int mu_ADR_COUNT = 1;
const int mu_O_NET_MAX = 12;
const int mu_U_NET_MAX = 12;
const int mu_load = 1;
const int mu_store = 2;
const int mu_none = 3;
const int mu_Fwd_GetM = 4;
const int mu_GetM = 5;
const int mu_GetM_Ack_D = 6;
const int mu_PutM = 7;
const int mu_Put_Ack = 8;
const int mu_cache_I = 9;
const int mu_cache_I_load = 10;
const int mu_cache_I_store = 11;
const int mu_cache_M = 12;
const int mu_cache_M_evict = 13;
const int mu_directory_I = 14;
const int mu_directory_M = 15;
const int mu_Address_1 = 16;
const int mu_OBJSET_cache_1 = 17;
const int mu_OBJSET_cache_2 = 18;
const int mu_OBJSET_cache_3 = 19;
const int mu_directory = 20;
/*** Variable declaration ***/
mu_1_OBJ_cache mu_i_cache("i_cache",0);

/*** Variable declaration ***/
mu_1_OBJ_directory mu_i_directory("i_directory",72);

/*** Variable declaration ***/
mu_1_OBJ_Ordered mu_fwd("fwd",104);

/*** Variable declaration ***/
mu_1_OBJ_Orderedcnt mu_cnt_fwd("cnt_fwd",2024);

/*** Variable declaration ***/
mu_1_OBJ_Unordered mu_resp("resp",2056);

/*** Variable declaration ***/
mu_1_OBJ_Unordered mu_req("req",4360);

/*** Variable declaration ***/
mu_1_CL_MUTEX mu_cl_mut("cl_mut",6664);

mu_1_Message mu_Request(const mu_1_Address& mu_adr,const mu_1_MessageType& mu_mtype,const mu_1_Machines& mu_src,const mu_1_Machines& mu_dst)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

if (mu_adr.isundefined())
  mu_msg.mu_adr.undefine();
else
  mu_msg.mu_adr = mu_adr;
if (mu_mtype.isundefined())
  mu_msg.mu_mtype.undefine();
else
  mu_msg.mu_mtype = mu_mtype;
if (mu_src.isundefined())
  mu_msg.mu_src.undefine();
else
  mu_msg.mu_src = mu_src;
if (mu_dst.isundefined())
  mu_msg.mu_dst.undefine();
else
  mu_msg.mu_dst = mu_dst;
mu_msg.mu_cl.undefine();
return mu_msg;
	Error.Error("The end of function Request reached without returning values.");
};
/*** end function declaration ***/

mu_1_Message mu_Ack(const mu_1_Address& mu_adr,const mu_1_MessageType& mu_mtype,const mu_1_Machines& mu_src,const mu_1_Machines& mu_dst)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

if (mu_adr.isundefined())
  mu_msg.mu_adr.undefine();
else
  mu_msg.mu_adr = mu_adr;
if (mu_mtype.isundefined())
  mu_msg.mu_mtype.undefine();
else
  mu_msg.mu_mtype = mu_mtype;
if (mu_src.isundefined())
  mu_msg.mu_src.undefine();
else
  mu_msg.mu_src = mu_src;
if (mu_dst.isundefined())
  mu_msg.mu_dst.undefine();
else
  mu_msg.mu_dst = mu_dst;
mu_msg.mu_cl.undefine();
return mu_msg;
	Error.Error("The end of function Ack reached without returning values.");
};
/*** end function declaration ***/

mu_1_Message mu_Resp(const mu_1_Address& mu_adr,const mu_1_MessageType& mu_mtype,const mu_1_Machines& mu_src,const mu_1_Machines& mu_dst,const mu_1_ClValue& mu_cl)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

if (mu_adr.isundefined())
  mu_msg.mu_adr.undefine();
else
  mu_msg.mu_adr = mu_adr;
if (mu_mtype.isundefined())
  mu_msg.mu_mtype.undefine();
else
  mu_msg.mu_mtype = mu_mtype;
if (mu_src.isundefined())
  mu_msg.mu_src.undefine();
else
  mu_msg.mu_src = mu_src;
if (mu_dst.isundefined())
  mu_msg.mu_dst.undefine();
else
  mu_msg.mu_dst = mu_dst;
if (mu_cl.isundefined())
  mu_msg.mu_cl.undefine();
else
  mu_msg.mu_cl = mu_cl;
return mu_msg;
	Error.Error("The end of function Resp reached without returning values.");
};
/*** end function declaration ***/

mu_1_Message mu_RespAck(const mu_1_Address& mu_adr,const mu_1_MessageType& mu_mtype,const mu_1_Machines& mu_src,const mu_1_Machines& mu_dst,const mu_1_ClValue& mu_cl)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

if (mu_adr.isundefined())
  mu_msg.mu_adr.undefine();
else
  mu_msg.mu_adr = mu_adr;
if (mu_mtype.isundefined())
  mu_msg.mu_mtype.undefine();
else
  mu_msg.mu_mtype = mu_mtype;
if (mu_src.isundefined())
  mu_msg.mu_src.undefine();
else
  mu_msg.mu_src = mu_src;
if (mu_dst.isundefined())
  mu_msg.mu_dst.undefine();
else
  mu_msg.mu_dst = mu_dst;
if (mu_cl.isundefined())
  mu_msg.mu_cl.undefine();
else
  mu_msg.mu_cl = mu_cl;
return mu_msg;
	Error.Error("The end of function RespAck reached without returning values.");
};
/*** end function declaration ***/

void mu_Aquire_Mutex(const mu_1_Address& mu_adr)
{
mu_cl_mut[mu_adr] = mu_true;
};
/*** end procedure declaration ***/

void mu_Release_Mutex(const mu_1_Address& mu_adr)
{
mu_cl_mut[mu_adr] = mu_false;
};
/*** end procedure declaration ***/

void mu_Send_fwd(mu_1_Message& mu_msg)
{
if ( !((mu_cnt_fwd[mu_msg.mu_dst]) < (mu_O_NET_MAX)) ) Error.Error("Assertion failed: Too many messages");
mu_fwd[mu_msg.mu_dst][mu_cnt_fwd[mu_msg.mu_dst]] = mu_msg;
mu_cnt_fwd[mu_msg.mu_dst] = (mu_cnt_fwd[mu_msg.mu_dst]) + (1);
};
/*** end procedure declaration ***/

void mu_Pop_fwd(const mu_1_Machines& mu_n)
{
if ( !((mu_cnt_fwd[mu_n]) > (0)) ) Error.Error("Assertion failed: Trying to advance empty Q");
{
int mu__ub5 = (mu_cnt_fwd[mu_n]) - (1);
for (int mu_i = 0; mu_i <= mu__ub5; mu_i += 1) {
if ( (mu_i) < ((mu_cnt_fwd[mu_n]) - (1)) )
{
mu_fwd[mu_n][mu_i] = mu_fwd[mu_n][(mu_i) + (1)];
}
else
{
mu_fwd[mu_n][mu_i].undefine();
}
};
};
mu_cnt_fwd[mu_n] = (mu_cnt_fwd[mu_n]) - (1);
};
/*** end procedure declaration ***/

void mu_Send_resp(mu_1_Message& mu_msg)
{
/*** begin multisetcount 0 declaration ***/
  int mu__intexpr6 = 0;
  {
  mu_1__type_4_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_resp[mu_msg.mu_dst].valid[(int)mu_i].value())
	{
	  if ( mu_true ) mu__intexpr6++;
	}
      if (mu_i == 12-1) break;
    }
  }
/*** end multisetcount 0 declaration ***/
if ( !((mu__intexpr6) < (mu_U_NET_MAX)) ) Error.Error("Assertion failed: Too many messages");
mu_resp[mu_msg.mu_dst].multisetadd(mu_msg);
};
/*** end procedure declaration ***/

void mu_Send_req(mu_1_Message& mu_msg)
{
/*** begin multisetcount 1 declaration ***/
  int mu__intexpr7 = 0;
  {
  mu_1__type_4_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_req[mu_msg.mu_dst].valid[(int)mu_i].value())
	{
	  if ( mu_true ) mu__intexpr7++;
	}
      if (mu_i == 12-1) break;
    }
  }
/*** end multisetcount 1 declaration ***/
if ( !((mu__intexpr7) < (mu_U_NET_MAX)) ) Error.Error("Assertion failed: Too many messages");
mu_req[mu_msg.mu_dst].multisetadd(mu_msg);
};
/*** end procedure declaration ***/

mu_0_boolean mu_Func_cache(mu_1_Message& mu_inmsg,const mu_1_OBJSET_cache& mu_m)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

{
  const int mu_adr = mu_inmsg.mu_adr;
{
  mu_1_ENTRY_cache& mu_cache_entry = mu_i_cache[mu_m].mu_CL[mu_adr];
switch ((int) mu_cache_entry.mu_State) {
case mu_cache_I:
return mu_false;
break;
case mu_cache_I_load:
switch ((int) mu_inmsg.mu_mtype) {
case mu_GetM_Ack_D:
if (mu_inmsg.mu_cl.isundefined())
  mu_cache_entry.mu_cl.undefine();
else
  mu_cache_entry.mu_cl = mu_inmsg.mu_cl;
mu_cache_entry.mu_State = mu_cache_M;
mu_Release_Mutex ( mu_adr );
break;
default:
return mu_false;
break;
}
break;
case mu_cache_I_store:
switch ((int) mu_inmsg.mu_mtype) {
case mu_GetM_Ack_D:
if (mu_inmsg.mu_cl.isundefined())
  mu_cache_entry.mu_cl.undefine();
else
  mu_cache_entry.mu_cl = mu_inmsg.mu_cl;
mu_cache_entry.mu_State = mu_cache_M;
mu_Release_Mutex ( mu_adr );
break;
default:
return mu_false;
break;
}
break;
case mu_cache_M:
switch ((int) mu_inmsg.mu_mtype) {
case mu_Fwd_GetM:
mu_msg = mu_Resp( mu_adr, mu_GetM_Ack_D, (int)mu_m, mu_inmsg.mu_src, mu_cache_entry.mu_cl );
mu_Send_resp ( mu_msg );
mu_cache_entry.mu_State = mu_cache_I;
break;
default:
return mu_false;
break;
}
break;
case mu_cache_M_evict:
switch ((int) mu_inmsg.mu_mtype) {
case mu_Put_Ack:
mu_cache_entry.mu_State = mu_cache_I;
mu_Release_Mutex ( mu_adr );
break;
default:
return mu_false;
break;
}
break;
}
}
}
return mu_true;
	Error.Error("The end of function Func_cache reached without returning values.");
};
/*** end function declaration ***/

mu_0_boolean mu_Func_directory(mu_1_Message& mu_inmsg,const mu_1_OBJSET_directory& mu_m)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

{
  const int mu_adr = mu_inmsg.mu_adr;
{
  mu_1_ENTRY_directory& mu_directory_entry = mu_i_directory[mu_m].mu_CL[mu_adr];
switch ((int) mu_directory_entry.mu_State) {
case mu_directory_I:
switch ((int) mu_inmsg.mu_mtype) {
case mu_GetM:
mu_msg = mu_Resp( mu_adr, mu_GetM_Ack_D, (int)mu_m, mu_inmsg.mu_src, mu_directory_entry.mu_cl );
mu_Send_resp ( mu_msg );
if (mu_inmsg.mu_src.isundefined())
  mu_directory_entry.mu_owner.undefine();
else
  mu_directory_entry.mu_owner = mu_inmsg.mu_src;
mu_directory_entry.mu_State = mu_directory_M;
break;
default:
return mu_false;
break;
}
break;
case mu_directory_M:
switch ((int) mu_inmsg.mu_mtype) {
case mu_GetM:
mu_msg = mu_Request( mu_adr, mu_Fwd_GetM, mu_inmsg.mu_src, mu_directory_entry.mu_owner );
mu_Send_fwd ( mu_msg );
if (mu_inmsg.mu_src.isundefined())
  mu_directory_entry.mu_owner.undefine();
else
  mu_directory_entry.mu_owner = mu_inmsg.mu_src;
break;
case mu_PutM:
mu_msg = mu_Ack( mu_adr, mu_Put_Ack, (int)mu_m, mu_inmsg.mu_src );
mu_Send_fwd ( mu_msg );
if ( (mu_directory_entry.mu_owner) == (mu_inmsg.mu_src) )
{
if (mu_inmsg.mu_cl.isundefined())
  mu_directory_entry.mu_cl.undefine();
else
  mu_directory_entry.mu_cl = mu_inmsg.mu_cl;
mu_directory_entry.mu_State = mu_directory_I;
}
break;
default:
return mu_false;
break;
}
break;
}
}
}
return mu_true;
	Error.Error("The end of function Func_directory reached without returning values.");
};
/*** end function declaration ***/

void mu_SEND_cache_I_store(const mu_1_Address& mu_adr, const mu_1_OBJSET_cache& mu_m)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

{
  mu_1_ENTRY_cache& mu_cache_entry = mu_i_cache[mu_m].mu_CL[mu_adr];
mu_msg = mu_Request( mu_adr, mu_GetM, (int)mu_m, (int)mu_directory );
mu_Send_req ( mu_msg );
mu_cache_entry.mu_State = mu_cache_I_store;
}
};
/*** end procedure declaration ***/

void mu_SEND_cache_I_load(const mu_1_Address& mu_adr, const mu_1_OBJSET_cache& mu_m)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

{
  mu_1_ENTRY_cache& mu_cache_entry = mu_i_cache[mu_m].mu_CL[mu_adr];
mu_msg = mu_Request( mu_adr, mu_GetM, (int)mu_m, (int)mu_directory );
mu_Send_req ( mu_msg );
mu_cache_entry.mu_State = mu_cache_I_load;
}
};
/*** end procedure declaration ***/

void mu_SEND_cache_M_load(const mu_1_Address& mu_adr, const mu_1_OBJSET_cache& mu_m)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

{
  mu_1_ENTRY_cache& mu_cache_entry = mu_i_cache[mu_m].mu_CL[mu_adr];
mu_Release_Mutex ( mu_adr );
}
};
/*** end procedure declaration ***/

void mu_SEND_cache_M_store(const mu_1_Address& mu_adr, const mu_1_OBJSET_cache& mu_m)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

{
  mu_1_ENTRY_cache& mu_cache_entry = mu_i_cache[mu_m].mu_CL[mu_adr];
mu_Release_Mutex ( mu_adr );
}
};
/*** end procedure declaration ***/

void mu_SEND_cache_M_evict(const mu_1_Address& mu_adr, const mu_1_OBJSET_cache& mu_m)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

{
  mu_1_ENTRY_cache& mu_cache_entry = mu_i_cache[mu_m].mu_CL[mu_adr];
mu_msg = mu_Resp( mu_adr, mu_PutM, (int)mu_m, (int)mu_directory, mu_cache_entry.mu_cl );
mu_Send_req ( mu_msg );
mu_cache_entry.mu_State = mu_cache_M_evict;
}
};
/*** end procedure declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_i_cache.clear();
  mu_i_directory.clear();
  mu_fwd.clear();
  mu_cnt_fwd.clear();
  mu_resp.clear();
  mu_req.clear();
  mu_cl_mut.clear();
}
void world_class::undefine()
{
  mu_i_cache.undefine();
  mu_i_directory.undefine();
  mu_fwd.undefine();
  mu_cnt_fwd.undefine();
  mu_resp.undefine();
  mu_req.undefine();
  mu_cl_mut.undefine();
}
void world_class::reset()
{
  mu_i_cache.reset();
  mu_i_directory.reset();
  mu_fwd.reset();
  mu_cnt_fwd.reset();
  mu_resp.reset();
  mu_req.reset();
  mu_cl_mut.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_i_cache.print();
  mu_i_directory.print();
  mu_fwd.print();
  mu_cnt_fwd.print();
  mu_resp.print();
  mu_req.print();
  mu_cl_mut.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_i_cache.print_statistic();
  mu_i_directory.print_statistic();
  mu_fwd.print_statistic();
  mu_cnt_fwd.print_statistic();
  mu_resp.print_statistic();
  mu_req.print_statistic();
  mu_cl_mut.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_i_cache.print_diff(prevstate);
    mu_i_directory.print_diff(prevstate);
    mu_fwd.print_diff(prevstate);
    mu_cnt_fwd.print_diff(prevstate);
    mu_resp.print_diff(prevstate);
    mu_req.print_diff(prevstate);
    mu_cl_mut.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_i_cache.to_state( newstate );
  mu_i_directory.to_state( newstate );
  mu_fwd.to_state( newstate );
  mu_cnt_fwd.to_state( newstate );
  mu_resp.to_state( newstate );
  mu_req.to_state( newstate );
  mu_cl_mut.to_state( newstate );
}
void world_class::setstate(state *thestate)
{
}


/********************
  Rule declarations
 ********************/
/******************** RuleBase0 ********************/
class RuleBase0
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1__type_4_id mu_midx;
    mu_midx.value((r % 12) + 0);
    r = r / 12;
    static mu_1_Machines mu_n;
    mu_n.unionassign(r % 4);
    r = r / 4;
    return tsprintf("Receive req, midx:%s, n:%s", mu_midx.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1__type_4_id mu_midx;
    mu_midx.value((r % 12) + 0);
    r = r / 12;
    static mu_1_Machines mu_n;
    mu_n.unionassign(r % 4);
    r = r / 4;
  if (!mu_req[mu_n].in(mu_midx)) { return FALSE; }
  mu_1__type_4& mu_mach = mu_req[mu_n];
  mu_1_Message& mu_msg = mu_mach[mu_midx];
    return !(mu_msg.mu_mtype.isundefined());
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu_1__type_4_id mu_midx;
    mu_midx.value((r % 12) + 0);
    r = r / 12;
    static mu_1_Machines mu_n;
    mu_n.unionassign(r % 4);
    r = r / 4;
    while (what_rule < 48 && mu_midx.value()<12 )
      {
	if ( ( TRUE && mu_req[mu_n].in(mu_midx) ) ) {
  mu_1__type_4& mu_mach = mu_req[mu_n];
  mu_1_Message& mu_msg = mu_mach[mu_midx];
	      if (!(mu_msg.mu_mtype.isundefined())) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 0;
    mu_midx.value((r % 12) + 0);
    r = r / 12;
    mu_n.unionassign(r % 4);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu_1__type_4_id mu_midx;
    mu_midx.value((r % 12) + 0);
    r = r / 12;
    static mu_1_Machines mu_n;
    mu_n.unionassign(r % 4);
    r = r / 4;
  mu_1__type_4& mu_mach = mu_req[mu_n];
  mu_1_Message& mu_msg = mu_mach[mu_midx];
if ( (mu_n>=20 && mu_n<=20) )
{
if ( mu_Func_directory( mu_msg, (int)mu_n ) )
{
mu_mach.multisetremove(mu_midx);
}
}
else
{
if ( mu_Func_cache( mu_msg, (int)mu_n ) )
{
mu_mach.multisetremove(mu_midx);
}
}
  };

};
/******************** RuleBase1 ********************/
class RuleBase1
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1__type_4_id mu_midx;
    mu_midx.value((r % 12) + 0);
    r = r / 12;
    static mu_1_Machines mu_n;
    mu_n.unionassign(r % 4);
    r = r / 4;
    return tsprintf("Receive resp, midx:%s, n:%s", mu_midx.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1__type_4_id mu_midx;
    mu_midx.value((r % 12) + 0);
    r = r / 12;
    static mu_1_Machines mu_n;
    mu_n.unionassign(r % 4);
    r = r / 4;
  if (!mu_resp[mu_n].in(mu_midx)) { return FALSE; }
  mu_1__type_4& mu_mach = mu_resp[mu_n];
  mu_1_Message& mu_msg = mu_mach[mu_midx];
    return !(mu_msg.mu_mtype.isundefined());
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 48;
    static mu_1__type_4_id mu_midx;
    mu_midx.value((r % 12) + 0);
    r = r / 12;
    static mu_1_Machines mu_n;
    mu_n.unionassign(r % 4);
    r = r / 4;
    while (what_rule < 96 && mu_midx.value()<12 )
      {
	if ( ( TRUE && mu_resp[mu_n].in(mu_midx) ) ) {
  mu_1__type_4& mu_mach = mu_resp[mu_n];
  mu_1_Message& mu_msg = mu_mach[mu_midx];
	      if (!(mu_msg.mu_mtype.isundefined())) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 48;
    mu_midx.value((r % 12) + 0);
    r = r / 12;
    mu_n.unionassign(r % 4);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu_1__type_4_id mu_midx;
    mu_midx.value((r % 12) + 0);
    r = r / 12;
    static mu_1_Machines mu_n;
    mu_n.unionassign(r % 4);
    r = r / 4;
  mu_1__type_4& mu_mach = mu_resp[mu_n];
  mu_1_Message& mu_msg = mu_mach[mu_midx];
if ( (mu_n>=20 && mu_n<=20) )
{
if ( mu_Func_directory( mu_msg, (int)mu_n ) )
{
mu_mach.multisetremove(mu_midx);
}
}
else
{
if ( mu_Func_cache( mu_msg, (int)mu_n ) )
{
mu_mach.multisetremove(mu_midx);
}
}
  };

};
/******************** RuleBase2 ********************/
class RuleBase2
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Machines mu_n;
    mu_n.unionassign(r % 4);
    r = r / 4;
    return tsprintf("Receive fwd, n:%s", mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Machines mu_n;
    mu_n.unionassign(r % 4);
    r = r / 4;
  mu_1_Message& mu_msg = mu_fwd[mu_n][0];
    return (mu_cnt_fwd[mu_n]) > (0);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 96;
    static mu_1_Machines mu_n;
    mu_n.unionassign(r % 4);
    r = r / 4;
    while (what_rule < 100 )
      {
	if ( ( TRUE  ) ) {
  mu_1_Message& mu_msg = mu_fwd[mu_n][0];
	      if ((mu_cnt_fwd[mu_n]) > (0)) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 96;
    mu_n.unionassign(r % 4);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Machines mu_n;
    mu_n.unionassign(r % 4);
    r = r / 4;
  mu_1_Message& mu_msg = mu_fwd[mu_n][0];
if ( (mu_n>=20 && mu_n<=20) )
{
if ( mu_Func_directory( mu_msg, (int)mu_n ) )
{
mu_Pop_fwd ( mu_n );
}
}
else
{
if ( mu_Func_cache( mu_msg, (int)mu_n ) )
{
mu_Pop_fwd ( mu_n );
}
}
  };

};
/******************** RuleBase3 ********************/
class RuleBase3
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Address mu_adr;
    mu_adr.value((r % 1) + 16);
    r = r / 1;
    static mu_1_OBJSET_cache mu_m;
    mu_m.value((r % 3) + 17);
    r = r / 3;
    return tsprintf("cache_M_evict, adr:%s, m:%s", mu_adr.Name(), mu_m.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_adr;
    mu_adr.value((r % 1) + 16);
    r = r / 1;
    static mu_1_OBJSET_cache mu_m;
    mu_m.value((r % 3) + 17);
    r = r / 3;
  mu_1_ENTRY_cache& mu_cle = mu_i_cache[mu_m].mu_CL[mu_adr];
bool mu__boolexpr8;
  if (!((mu_cle.mu_State) == (mu_cache_M))) mu__boolexpr8 = FALSE ;
  else {
  mu__boolexpr8 = ((mu_cl_mut[mu_adr]) == (mu_false)) ; 
}
    return mu__boolexpr8;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 100;
    static mu_1_Address mu_adr;
    mu_adr.value((r % 1) + 16);
    r = r / 1;
    static mu_1_OBJSET_cache mu_m;
    mu_m.value((r % 3) + 17);
    r = r / 3;
    while (what_rule < 103 )
      {
	if ( ( TRUE  ) ) {
  mu_1_ENTRY_cache& mu_cle = mu_i_cache[mu_m].mu_CL[mu_adr];
bool mu__boolexpr9;
  if (!((mu_cle.mu_State) == (mu_cache_M))) mu__boolexpr9 = FALSE ;
  else {
  mu__boolexpr9 = ((mu_cl_mut[mu_adr]) == (mu_false)) ; 
}
	      if (mu__boolexpr9) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 100;
    mu_adr.value((r % 1) + 16);
    r = r / 1;
    mu_m.value((r % 3) + 17);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_adr;
    mu_adr.value((r % 1) + 16);
    r = r / 1;
    static mu_1_OBJSET_cache mu_m;
    mu_m.value((r % 3) + 17);
    r = r / 3;
  mu_1_ENTRY_cache& mu_cle = mu_i_cache[mu_m].mu_CL[mu_adr];
mu_Aquire_Mutex ( mu_adr );
mu_SEND_cache_M_evict ( mu_adr, mu_m );
  };

};
/******************** RuleBase4 ********************/
class RuleBase4
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Address mu_adr;
    mu_adr.value((r % 1) + 16);
    r = r / 1;
    static mu_1_OBJSET_cache mu_m;
    mu_m.value((r % 3) + 17);
    r = r / 3;
    return tsprintf("cache_M_store, adr:%s, m:%s", mu_adr.Name(), mu_m.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_adr;
    mu_adr.value((r % 1) + 16);
    r = r / 1;
    static mu_1_OBJSET_cache mu_m;
    mu_m.value((r % 3) + 17);
    r = r / 3;
  mu_1_ENTRY_cache& mu_cle = mu_i_cache[mu_m].mu_CL[mu_adr];
bool mu__boolexpr10;
  if (!((mu_cle.mu_State) == (mu_cache_M))) mu__boolexpr10 = FALSE ;
  else {
  mu__boolexpr10 = ((mu_cl_mut[mu_adr]) == (mu_false)) ; 
}
    return mu__boolexpr10;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 103;
    static mu_1_Address mu_adr;
    mu_adr.value((r % 1) + 16);
    r = r / 1;
    static mu_1_OBJSET_cache mu_m;
    mu_m.value((r % 3) + 17);
    r = r / 3;
    while (what_rule < 106 )
      {
	if ( ( TRUE  ) ) {
  mu_1_ENTRY_cache& mu_cle = mu_i_cache[mu_m].mu_CL[mu_adr];
bool mu__boolexpr11;
  if (!((mu_cle.mu_State) == (mu_cache_M))) mu__boolexpr11 = FALSE ;
  else {
  mu__boolexpr11 = ((mu_cl_mut[mu_adr]) == (mu_false)) ; 
}
	      if (mu__boolexpr11) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 103;
    mu_adr.value((r % 1) + 16);
    r = r / 1;
    mu_m.value((r % 3) + 17);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_adr;
    mu_adr.value((r % 1) + 16);
    r = r / 1;
    static mu_1_OBJSET_cache mu_m;
    mu_m.value((r % 3) + 17);
    r = r / 3;
  mu_1_ENTRY_cache& mu_cle = mu_i_cache[mu_m].mu_CL[mu_adr];
mu_Aquire_Mutex ( mu_adr );
mu_SEND_cache_M_store ( mu_adr, mu_m );
  };

};
/******************** RuleBase5 ********************/
class RuleBase5
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Address mu_adr;
    mu_adr.value((r % 1) + 16);
    r = r / 1;
    static mu_1_OBJSET_cache mu_m;
    mu_m.value((r % 3) + 17);
    r = r / 3;
    return tsprintf("cache_M_load, adr:%s, m:%s", mu_adr.Name(), mu_m.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_adr;
    mu_adr.value((r % 1) + 16);
    r = r / 1;
    static mu_1_OBJSET_cache mu_m;
    mu_m.value((r % 3) + 17);
    r = r / 3;
  mu_1_ENTRY_cache& mu_cle = mu_i_cache[mu_m].mu_CL[mu_adr];
bool mu__boolexpr12;
  if (!((mu_cle.mu_State) == (mu_cache_M))) mu__boolexpr12 = FALSE ;
  else {
  mu__boolexpr12 = ((mu_cl_mut[mu_adr]) == (mu_false)) ; 
}
    return mu__boolexpr12;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 106;
    static mu_1_Address mu_adr;
    mu_adr.value((r % 1) + 16);
    r = r / 1;
    static mu_1_OBJSET_cache mu_m;
    mu_m.value((r % 3) + 17);
    r = r / 3;
    while (what_rule < 109 )
      {
	if ( ( TRUE  ) ) {
  mu_1_ENTRY_cache& mu_cle = mu_i_cache[mu_m].mu_CL[mu_adr];
bool mu__boolexpr13;
  if (!((mu_cle.mu_State) == (mu_cache_M))) mu__boolexpr13 = FALSE ;
  else {
  mu__boolexpr13 = ((mu_cl_mut[mu_adr]) == (mu_false)) ; 
}
	      if (mu__boolexpr13) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 106;
    mu_adr.value((r % 1) + 16);
    r = r / 1;
    mu_m.value((r % 3) + 17);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_adr;
    mu_adr.value((r % 1) + 16);
    r = r / 1;
    static mu_1_OBJSET_cache mu_m;
    mu_m.value((r % 3) + 17);
    r = r / 3;
  mu_1_ENTRY_cache& mu_cle = mu_i_cache[mu_m].mu_CL[mu_adr];
mu_Aquire_Mutex ( mu_adr );
mu_SEND_cache_M_load ( mu_adr, mu_m );
  };

};
/******************** RuleBase6 ********************/
class RuleBase6
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Address mu_adr;
    mu_adr.value((r % 1) + 16);
    r = r / 1;
    static mu_1_OBJSET_cache mu_m;
    mu_m.value((r % 3) + 17);
    r = r / 3;
    return tsprintf("cache_I_load, adr:%s, m:%s", mu_adr.Name(), mu_m.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_adr;
    mu_adr.value((r % 1) + 16);
    r = r / 1;
    static mu_1_OBJSET_cache mu_m;
    mu_m.value((r % 3) + 17);
    r = r / 3;
  mu_1_ENTRY_cache& mu_cle = mu_i_cache[mu_m].mu_CL[mu_adr];
bool mu__boolexpr14;
  if (!((mu_cle.mu_State) == (mu_cache_I))) mu__boolexpr14 = FALSE ;
  else {
  mu__boolexpr14 = ((mu_cl_mut[mu_adr]) == (mu_false)) ; 
}
    return mu__boolexpr14;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 109;
    static mu_1_Address mu_adr;
    mu_adr.value((r % 1) + 16);
    r = r / 1;
    static mu_1_OBJSET_cache mu_m;
    mu_m.value((r % 3) + 17);
    r = r / 3;
    while (what_rule < 112 )
      {
	if ( ( TRUE  ) ) {
  mu_1_ENTRY_cache& mu_cle = mu_i_cache[mu_m].mu_CL[mu_adr];
bool mu__boolexpr15;
  if (!((mu_cle.mu_State) == (mu_cache_I))) mu__boolexpr15 = FALSE ;
  else {
  mu__boolexpr15 = ((mu_cl_mut[mu_adr]) == (mu_false)) ; 
}
	      if (mu__boolexpr15) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 109;
    mu_adr.value((r % 1) + 16);
    r = r / 1;
    mu_m.value((r % 3) + 17);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_adr;
    mu_adr.value((r % 1) + 16);
    r = r / 1;
    static mu_1_OBJSET_cache mu_m;
    mu_m.value((r % 3) + 17);
    r = r / 3;
  mu_1_ENTRY_cache& mu_cle = mu_i_cache[mu_m].mu_CL[mu_adr];
mu_Aquire_Mutex ( mu_adr );
mu_SEND_cache_I_load ( mu_adr, mu_m );
  };

};
/******************** RuleBase7 ********************/
class RuleBase7
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Address mu_adr;
    mu_adr.value((r % 1) + 16);
    r = r / 1;
    static mu_1_OBJSET_cache mu_m;
    mu_m.value((r % 3) + 17);
    r = r / 3;
    return tsprintf("cache_I_store, adr:%s, m:%s", mu_adr.Name(), mu_m.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_adr;
    mu_adr.value((r % 1) + 16);
    r = r / 1;
    static mu_1_OBJSET_cache mu_m;
    mu_m.value((r % 3) + 17);
    r = r / 3;
  mu_1_ENTRY_cache& mu_cle = mu_i_cache[mu_m].mu_CL[mu_adr];
bool mu__boolexpr16;
  if (!((mu_cle.mu_State) == (mu_cache_I))) mu__boolexpr16 = FALSE ;
  else {
  mu__boolexpr16 = ((mu_cl_mut[mu_adr]) == (mu_false)) ; 
}
    return mu__boolexpr16;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 112;
    static mu_1_Address mu_adr;
    mu_adr.value((r % 1) + 16);
    r = r / 1;
    static mu_1_OBJSET_cache mu_m;
    mu_m.value((r % 3) + 17);
    r = r / 3;
    while (what_rule < 115 )
      {
	if ( ( TRUE  ) ) {
  mu_1_ENTRY_cache& mu_cle = mu_i_cache[mu_m].mu_CL[mu_adr];
bool mu__boolexpr17;
  if (!((mu_cle.mu_State) == (mu_cache_I))) mu__boolexpr17 = FALSE ;
  else {
  mu__boolexpr17 = ((mu_cl_mut[mu_adr]) == (mu_false)) ; 
}
	      if (mu__boolexpr17) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 112;
    mu_adr.value((r % 1) + 16);
    r = r / 1;
    mu_m.value((r % 3) + 17);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_adr;
    mu_adr.value((r % 1) + 16);
    r = r / 1;
    static mu_1_OBJSET_cache mu_m;
    mu_m.value((r % 3) + 17);
    r = r / 3;
  mu_1_ENTRY_cache& mu_cle = mu_i_cache[mu_m].mu_CL[mu_adr];
mu_Aquire_Mutex ( mu_adr );
mu_SEND_cache_I_store ( mu_adr, mu_m );
  };

};
class NextStateGenerator
{
  RuleBase0 R0;
  RuleBase1 R1;
  RuleBase2 R2;
  RuleBase3 R3;
  RuleBase4 R4;
  RuleBase5 R5;
  RuleBase6 R6;
  RuleBase7 R7;
public:
void SetNextEnabledRule(unsigned & what_rule)
{
  category = CONDITION;
  if (what_rule<48)
    { R0.NextRule(what_rule);
      if (what_rule<48) return; }
  if (what_rule>=48 && what_rule<96)
    { R1.NextRule(what_rule);
      if (what_rule<96) return; }
  if (what_rule>=96 && what_rule<100)
    { R2.NextRule(what_rule);
      if (what_rule<100) return; }
  if (what_rule>=100 && what_rule<103)
    { R3.NextRule(what_rule);
      if (what_rule<103) return; }
  if (what_rule>=103 && what_rule<106)
    { R4.NextRule(what_rule);
      if (what_rule<106) return; }
  if (what_rule>=106 && what_rule<109)
    { R5.NextRule(what_rule);
      if (what_rule<109) return; }
  if (what_rule>=109 && what_rule<112)
    { R6.NextRule(what_rule);
      if (what_rule<112) return; }
  if (what_rule>=112 && what_rule<115)
    { R7.NextRule(what_rule);
      if (what_rule<115) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=47) return R0.Condition(r-0);
  if (r>=48 && r<=95) return R1.Condition(r-48);
  if (r>=96 && r<=99) return R2.Condition(r-96);
  if (r>=100 && r<=102) return R3.Condition(r-100);
  if (r>=103 && r<=105) return R4.Condition(r-103);
  if (r>=106 && r<=108) return R5.Condition(r-106);
  if (r>=109 && r<=111) return R6.Condition(r-109);
  if (r>=112 && r<=114) return R7.Condition(r-112);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
return 0;}
void Code(unsigned r)
{
  if (r<=47) { R0.Code(r-0); return; } 
  if (r>=48 && r<=95) { R1.Code(r-48); return; } 
  if (r>=96 && r<=99) { R2.Code(r-96); return; } 
  if (r>=100 && r<=102) { R3.Code(r-100); return; } 
  if (r>=103 && r<=105) { R4.Code(r-103); return; } 
  if (r>=106 && r<=108) { R5.Code(r-106); return; } 
  if (r>=109 && r<=111) { R6.Code(r-109); return; } 
  if (r>=112 && r<=114) { R7.Code(r-112); return; } 
}
int Priority(unsigned short r)
{
  if (r<=47) { return R0.Priority(); } 
  if (r>=48 && r<=95) { return R1.Priority(); } 
  if (r>=96 && r<=99) { return R2.Priority(); } 
  if (r>=100 && r<=102) { return R3.Priority(); } 
  if (r>=103 && r<=105) { return R4.Priority(); } 
  if (r>=106 && r<=108) { return R5.Priority(); } 
  if (r>=109 && r<=111) { return R6.Priority(); } 
  if (r>=112 && r<=114) { return R7.Priority(); } 
return 0;}
char * Name(unsigned r)
{
  if (r<=47) return R0.Name(r-0);
  if (r>=48 && r<=95) return R1.Name(r-48);
  if (r>=96 && r<=99) return R2.Name(r-96);
  if (r>=100 && r<=102) return R3.Name(r-100);
  if (r>=103 && r<=105) return R4.Name(r-103);
  if (r>=106 && r<=108) return R5.Name(r-106);
  if (r>=109 && r<=111) return R6.Name(r-109);
  if (r>=112 && r<=114) return R7.Name(r-112);
  return NULL;
}
};
const unsigned numrules = 115;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 115


/********************
  Startstate records
 ********************/
/******************** StartStateBase0 ********************/
class StartStateBase0
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("Startstate 0");
  }
  void Code(unsigned short r)
  {
{
for(int mu_i = 17; mu_i <= 19; mu_i++) {
{
for(int mu_a = 16; mu_a <= 16; mu_a++) {
mu_i_cache[mu_i].mu_CL[mu_a].mu_State = mu_cache_I;
mu_i_cache[mu_i].mu_CL[mu_a].mu_cl = 0;
mu_i_cache[mu_i].mu_CL[mu_a].mu_Perm = mu_none;
};
};
};
};
{
for(int mu_i = 20; mu_i <= 20; mu_i++) {
{
for(int mu_a = 16; mu_a <= 16; mu_a++) {
mu_i_directory[mu_i].mu_CL[mu_a].mu_State = mu_directory_I;
mu_i_directory[mu_i].mu_CL[mu_a].mu_cl = 0;
mu_i_directory[mu_i].mu_CL[mu_a].mu_Perm = mu_none;
};
};
};
};
mu_fwd.undefine();
{
for(int mu_n = 17; mu_n <= 20; mu_n++)
  if (( ( mu_n >= 20 ) && ( mu_n <= 20 ) )|| ( ( mu_n >= 17 ) && ( mu_n <= 19 ) )) {
mu_cnt_fwd[mu_n] = 0;
};
};
mu_resp.undefine();
mu_req.undefine();
{
for(int mu_a = 16; mu_a <= 16; mu_a++) {
mu_cl_mut[mu_a] = mu_false;
};
};
  };

};
class StartStateGenerator
{
  StartStateBase0 S0;
public:
void Code(unsigned short r)
{
  if (r<=0) { S0.Code(r-0); return; }
}
char * Name(unsigned short r)
{
  if (r<=0) return S0.Name(r-0);
  return NULL;
}
};
const rulerec startstates[] = {
{ NULL, NULL, NULL, FALSE},
};
unsigned short StartStateManager::numstartstates = 1;

/********************
  Invariant records
 ********************/
const rulerec invariants[] = {
{ NULL, NULL, NULL, FALSE }};
const unsigned short numinvariants = 0;

/********************
  Normal/Canonicalization for scalarset
 ********************/
/*
cl_mut:NoScalarset
i_directory:ScalarsetVariable
cnt_fwd:ScalarsetArrayOfFree
i_cache:ScalarsetArrayOfFree
fwd:ScalarsetArrayOfScalarset
req:Complex
resp:Complex
*/

/********************
Code for symmetry
 ********************/

/********************
 Permutation Set Class
 ********************/
class PermSet
{
public:
  // book keeping
  enum PresentationType {Simple, Explicit};
  PresentationType Presentation;

  void ResetToSimple();
  void ResetToExplicit();
  void SimpleToExplicit();
  void SimpleToOne();
  bool NextPermutation();

  void Print_in_size()
  { int ret=0; for (int i=0; i<count; i++) if (in[i]) ret++; cout << "in_size:" << ret << "\n"; }


  /********************
   Simple and efficient representation
   ********************/
  int class_mu_1_OBJSET_cache[3];
  int undefined_class_mu_1_OBJSET_cache;// has the highest class number

  void Print_class_mu_1_OBJSET_cache();
  bool OnlyOneRemain_mu_1_OBJSET_cache;
  bool MTO_class_mu_1_OBJSET_cache()
  {
    int i,j;
    if (OnlyOneRemain_mu_1_OBJSET_cache)
      return FALSE;
    for (i=0; i<3; i++)
      for (j=0; j<3; j++)
        if (i!=j && class_mu_1_OBJSET_cache[i]== class_mu_1_OBJSET_cache[j])
	    return TRUE;
    OnlyOneRemain_mu_1_OBJSET_cache = TRUE;
    return FALSE;
  }
  bool AlreadyOnlyOneRemain;
  bool MoreThanOneRemain();


  /********************
   Explicit representation
  ********************/
  unsigned long size;
  unsigned long count;
  // in will be of product of factorial sizes for fast canonicalize
  // in will be of size 1 for reduced local memory canonicalize
  bool * in;

  // auxiliary for explicit representation

  // in/perm/revperm will be of factorial size for fast canonicalize
  // they will be of size 1 for reduced local memory canonicalize
  // second range will be size of the scalarset
  int * in_mu_1_OBJSET_cache;
  typedef int arr_mu_1_OBJSET_cache[3];
  arr_mu_1_OBJSET_cache * perm_mu_1_OBJSET_cache;
  arr_mu_1_OBJSET_cache * revperm_mu_1_OBJSET_cache;

  int size_mu_1_OBJSET_cache[3];
  bool reversed_sorted_mu_1_OBJSET_cache(int start, int end);
  void reverse_reversed_mu_1_OBJSET_cache(int start, int end);

  // procedure for explicit representation
  bool ok0(mu_1_OBJSET_cache* perm, int size, mu_1_OBJSET_cache k);
  void GenPerm0(mu_1_OBJSET_cache* perm, int size, unsigned long& index);

  // General procedure
  PermSet();
  bool In(int i) const { return in[i]; };
  void Add(int i) { for (int j=0; j<i; j++) in[j] = FALSE;};
  void Remove(int i) { in[i] = FALSE; };
};
void PermSet::Print_class_mu_1_OBJSET_cache()
{
  cout << "class_mu_1_OBJSET_cache:\t";
  for (int i=0; i<3; i++)
    cout << class_mu_1_OBJSET_cache[i];
  cout << " " << undefined_class_mu_1_OBJSET_cache << "\n";
}
bool PermSet::MoreThanOneRemain()
{
  int i,j;
  if (AlreadyOnlyOneRemain)
    return FALSE;
  else {
    for (i=0; i<3; i++)
      for (j=0; j<3; j++)
        if (i!=j && class_mu_1_OBJSET_cache[i]== class_mu_1_OBJSET_cache[j])
	    return TRUE;
  }
  AlreadyOnlyOneRemain = TRUE;
  return FALSE;
}
PermSet::PermSet()
: Presentation(Simple)
{
  int i,j,k;
  if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize
     || args->sym_alg.mode == argsym_alg::Heuristic_Fast_Canonicalize) {
    mu_1_OBJSET_cache Perm0[3];

  /********************
   declaration of class variables
  ********************/
  in = new bool[6];
 in_mu_1_OBJSET_cache = new int[6];
 perm_mu_1_OBJSET_cache = new arr_mu_1_OBJSET_cache[6];
 revperm_mu_1_OBJSET_cache = new arr_mu_1_OBJSET_cache[6];

    // Set perm and revperm
    count = 0;
    for (i=17; i<=19; i++)
      {
        Perm0[0].value(i);
        GenPerm0(Perm0, 1, count);
      }
    if (count!=6)
      Error.Error( "unable to initialize PermSet");
    for (i=0; i<6; i++)
      for (j=17; j<=19; j++)
        for (k=17; k<=19; k++)
          if (revperm_mu_1_OBJSET_cache[i][k-17]==j)   // k - base 
            perm_mu_1_OBJSET_cache[i][j-17]=k; // j - base 

    // setting up combination of permutations
    // for different scalarset
    int carry;
    int i_mu_1_OBJSET_cache = 0;
    size = 6;
    count = 6;
    for (i=0; i<6; i++)
      {
        carry = 1;
        in[i]= TRUE;
      in_mu_1_OBJSET_cache[i] = i_mu_1_OBJSET_cache;
      i_mu_1_OBJSET_cache += carry;
      if (i_mu_1_OBJSET_cache >= 6) { i_mu_1_OBJSET_cache = 0; carry = 1; } 
      else { carry = 0; } 
    }
  }
  else
  {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];
 in_mu_1_OBJSET_cache = new int[1];
 perm_mu_1_OBJSET_cache = new arr_mu_1_OBJSET_cache[1];
 revperm_mu_1_OBJSET_cache = new arr_mu_1_OBJSET_cache[1];
  in[0] = TRUE;
    in_mu_1_OBJSET_cache[0] = 0;
  }
}
void PermSet::ResetToSimple()
{
  int i;
  for (i=0; i<3; i++)
    class_mu_1_OBJSET_cache[i]=0;
  undefined_class_mu_1_OBJSET_cache=0;
  OnlyOneRemain_mu_1_OBJSET_cache = FALSE;

  AlreadyOnlyOneRemain = FALSE;
  Presentation = Simple;
}
void PermSet::ResetToExplicit()
{
  for (int i=0; i<6; i++) in[i] = TRUE;
  Presentation = Explicit;
}
void PermSet::SimpleToExplicit()
{
  int i,j,k;
  int start, class_size;
  int start_mu_1_OBJSET_cache[3];
  int size_mu_1_OBJSET_cache[3];
  bool should_be_in_mu_1_OBJSET_cache[6];

  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_OBJSET_cache; j++) // class number
    {
      class_size = 0;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_OBJSET_cache[k]==j)
	  class_size++;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_OBJSET_cache[k]==j)
	  {
	    size_mu_1_OBJSET_cache[k] = class_size;
	    start_mu_1_OBJSET_cache[k] = start;
	  }
      start+=class_size;
    }

  // To be In or not to be
  for (i=0; i<6; i++) // set up
    should_be_in_mu_1_OBJSET_cache[i] = TRUE;
  for (i=0; i<6; i++) // to be in or not to be
    for (k=0; k<3; k++) // step through class_mu_1_pid[k]
      if (! (perm_mu_1_OBJSET_cache[i][k]-17 >=start_mu_1_OBJSET_cache[k] 
	     && perm_mu_1_OBJSET_cache[i][k]-17 < start_mu_1_OBJSET_cache[k] + size_mu_1_OBJSET_cache[k]) )
  	    {
	      should_be_in_mu_1_OBJSET_cache[i] = FALSE;
	      break;
	    }

  // setup explicit representation 
  // Set perm and revperm
  for (i=0; i<6; i++)
    {
      in[i] = TRUE;
      if (in[i] && !should_be_in_mu_1_OBJSET_cache[in_mu_1_OBJSET_cache[i]]) in[i] = FALSE;
    }
  Presentation = Explicit;
  if (args->test_parameter1.value==0) Print_in_size();
}
void PermSet::SimpleToOne()
{
  int i,j,k;
  int class_size;
  int start;


  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_OBJSET_cache; j++) // class number
    {
      class_size = 0;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_OBJSET_cache[k]==j)
	  class_size++;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_OBJSET_cache[k]==j)
	  {
	    size_mu_1_OBJSET_cache[k] = class_size;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_OBJSET_cache; j++) // class number
    {
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	    if (class_mu_1_OBJSET_cache[k]==j)
	      revperm_mu_1_OBJSET_cache[0][start++] = k+17;
    }
  for (j=0; j<3; j++)
    for (k=0; k<3; k++)
      if (revperm_mu_1_OBJSET_cache[0][k]==j+17)
        perm_mu_1_OBJSET_cache[0][j]=k+17;
  Presentation = Explicit;
}
bool PermSet::ok0(mu_1_OBJSET_cache* Perm, int size, mu_1_OBJSET_cache k)
{
  for (int i=0; i<size; i++)
    if(Perm[i].value()==k)
      return FALSE;
  return TRUE;
}
void PermSet::GenPerm0(mu_1_OBJSET_cache* Perm,int size, unsigned long& count)
{
  int i;
  if (size!=3)
    {
      for (i=17; i<=19; i++)
        if(ok0(Perm,size,i))
          {
            Perm[size].value(i);
            GenPerm0(Perm, size+1, count);
          }
    }
  else
    {
      for (i=17; i<=19; i++)
        revperm_mu_1_OBJSET_cache[count][i-17]=Perm[i-17].value();// i - base
      count++;
    }
}
bool PermSet::reversed_sorted_mu_1_OBJSET_cache(int start, int end)
{
  int i,j;

  for (i=start; i<end; i++)
    if (revperm_mu_1_OBJSET_cache[0][i]<revperm_mu_1_OBJSET_cache[0][i+1])
      return FALSE;
  return TRUE;
}
void PermSet::reverse_reversed_mu_1_OBJSET_cache(int start, int end)
{
  int i,j;
  int temp;

  for (i=start, j=end; i<j; i++,j--) 
    {
      temp = revperm_mu_1_OBJSET_cache[0][j];
      revperm_mu_1_OBJSET_cache[0][j] = revperm_mu_1_OBJSET_cache[0][i];
      revperm_mu_1_OBJSET_cache[0][i] = temp;
    }
}
bool PermSet::NextPermutation()
{
  bool nexted = FALSE;
  int start, end; 
  int class_size;
  int temp;
  int j,k;

  // algorithm
  // for each class
  //   if forall in the same class reverse_sorted, 
  //     { sort again; goto next class }
  //   else
  //     {
  //       nexted = TRUE;
  //       for (j from l to r)
  // 	       if (for all j+ are reversed sorted)
  // 	         {
  // 	           swap j, j+1
  // 	           sort all j+ again
  // 	           break;
  // 	         }
  //     }
  for (start = 0; start < 3; )
    {
      end = start-1+size_mu_1_OBJSET_cache[revperm_mu_1_OBJSET_cache[0][start]-17];
      if (reversed_sorted_mu_1_OBJSET_cache(start,end))
	       {
	  reverse_reversed_mu_1_OBJSET_cache(start,end);
	  start = end+1;
	}
      else
	{
	  nexted = TRUE;
	  for (j = start; j<end; j++)
	    {
	      if (reversed_sorted_mu_1_OBJSET_cache(j+1,end))
		{
		  for (k = end; k>j; k--)
		    {
		      if (revperm_mu_1_OBJSET_cache[0][j]<revperm_mu_1_OBJSET_cache[0][k])
			{
			  // swap j, k
			  temp = revperm_mu_1_OBJSET_cache[0][j];
			  revperm_mu_1_OBJSET_cache[0][j] = revperm_mu_1_OBJSET_cache[0][k];
			  revperm_mu_1_OBJSET_cache[0][k] = temp;
			  break;
			}
		    }
		  reverse_reversed_mu_1_OBJSET_cache(j+1,end);
		  break;
		}
	    }
	  break;
	}
    }
if (!nexted) return FALSE;
  for (j=0; j<3; j++)
    for (k=0; k<3; k++)
      if (revperm_mu_1_OBJSET_cache[0][k]==j+17)   // k - base 
	perm_mu_1_OBJSET_cache[0][j]=k+17; // j - base 
  return TRUE;
}

/********************
 Symmetry Class
 ********************/
class SymmetryClass
{
  PermSet Perm;
  bool BestInitialized;
  state BestPermutedState;

  // utilities
  void SetBestResult(int i, state* temp);
  void ResetBestResult() {BestInitialized = FALSE;};

public:
  // initializer
  SymmetryClass() : Perm(), BestInitialized(FALSE) {};
  ~SymmetryClass() {};

  void Normalize(state* s);

  void Exhaustive_Fast_Canonicalize(state *s);
  void Heuristic_Fast_Canonicalize(state *s);
  void Heuristic_Small_Mem_Canonicalize(state *s);
  void Heuristic_Fast_Normalize(state *s);

  void MultisetSort(state* s);
};


/********************
 Symmetry Class Members
 ********************/
void SymmetryClass::MultisetSort(state* s)
{
        mu_cl_mut.MultisetSort();
        mu_i_directory.MultisetSort();
        mu_cnt_fwd.MultisetSort();
        mu_i_cache.MultisetSort();
        mu_fwd.MultisetSort();
        mu_req.MultisetSort();
        mu_resp.MultisetSort();
}
void SymmetryClass::Normalize(state* s)
{
  switch (args->sym_alg.mode) {
  case argsym_alg::Exhaustive_Fast_Canonicalize:
    Exhaustive_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Canonicalize:
    Heuristic_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Small_Mem_Canonicalize:
    Heuristic_Small_Mem_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Normalize:
    Heuristic_Fast_Normalize(s);
    break;
  default:
    Heuristic_Fast_Canonicalize(s);
  }
}

/********************
 Permute and Canonicalize function for different types
 ********************/
void mu_1_Access::Permute(PermSet& Perm, int i) {};
void mu_1_Access::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_Access::Canonicalize(PermSet& Perm) {};
void mu_1_Access::SimpleLimit(PermSet& Perm) {};
void mu_1_Access::ArrayLimit(PermSet& Perm) {};
void mu_1_Access::Limit(PermSet& Perm) {};
void mu_1_Access::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_MessageType::Permute(PermSet& Perm, int i) {};
void mu_1_MessageType::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_MessageType::Canonicalize(PermSet& Perm) {};
void mu_1_MessageType::SimpleLimit(PermSet& Perm) {};
void mu_1_MessageType::ArrayLimit(PermSet& Perm) {};
void mu_1_MessageType::Limit(PermSet& Perm) {};
void mu_1_MessageType::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_cache_state::Permute(PermSet& Perm, int i) {};
void mu_1_cache_state::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_cache_state::Canonicalize(PermSet& Perm) {};
void mu_1_cache_state::SimpleLimit(PermSet& Perm) {};
void mu_1_cache_state::ArrayLimit(PermSet& Perm) {};
void mu_1_cache_state::Limit(PermSet& Perm) {};
void mu_1_cache_state::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_directory_state::Permute(PermSet& Perm, int i) {};
void mu_1_directory_state::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_directory_state::Canonicalize(PermSet& Perm) {};
void mu_1_directory_state::SimpleLimit(PermSet& Perm) {};
void mu_1_directory_state::ArrayLimit(PermSet& Perm) {};
void mu_1_directory_state::Limit(PermSet& Perm) {};
void mu_1_directory_state::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_Address::Permute(PermSet& Perm, int i) {}
void mu_1_Address::SimpleCanonicalize(PermSet& Perm) {}
void mu_1_Address::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Address::SimpleLimit(PermSet& Perm) {}
void mu_1_Address::ArrayLimit(PermSet& Perm) {}
void mu_1_Address::Limit(PermSet& Perm) {}
void mu_1_Address::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1_ClValue::Permute(PermSet& Perm, int i) {};
void mu_1_ClValue::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_ClValue::Canonicalize(PermSet& Perm) {};
void mu_1_ClValue::SimpleLimit(PermSet& Perm) {};
void mu_1_ClValue::ArrayLimit(PermSet& Perm) {};
void mu_1_ClValue::Limit(PermSet& Perm) {};
void mu_1_ClValue::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_OBJSET_cache::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined())
    value(Perm.perm_mu_1_OBJSET_cache[Perm.in_mu_1_OBJSET_cache[i]][value()-17]); // value - base
};
void mu_1_OBJSET_cache::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_OBJSET_cache[value()-17]==Perm.undefined_class_mu_1_OBJSET_cache) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<3; i++)
          if (Perm.class_mu_1_OBJSET_cache[i] == Perm.undefined_class_mu_1_OBJSET_cache && i!=value()-17)
            Perm.class_mu_1_OBJSET_cache[i]++;
        value(17 + Perm.undefined_class_mu_1_OBJSET_cache++);
      }
    else 
      {
        value(Perm.class_mu_1_OBJSET_cache[value()-17]+17);
      }
}
void mu_1_OBJSET_cache::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_OBJSET_cache::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_OBJSET_cache[value()-17]==Perm.undefined_class_mu_1_OBJSET_cache) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<3; i++)
          if (Perm.class_mu_1_OBJSET_cache[i] == Perm.undefined_class_mu_1_OBJSET_cache && i!=value()-17)
            Perm.class_mu_1_OBJSET_cache[i]++;
        Perm.undefined_class_mu_1_OBJSET_cache++;
      }
}
void mu_1_OBJSET_cache::ArrayLimit(PermSet& Perm) {}
void mu_1_OBJSET_cache::Limit(PermSet& Perm) {}
void mu_1_OBJSET_cache::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1_OBJSET_directory::Permute(PermSet& Perm, int i) {};
void mu_1_OBJSET_directory::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_OBJSET_directory::Canonicalize(PermSet& Perm) {};
void mu_1_OBJSET_directory::SimpleLimit(PermSet& Perm) {};
void mu_1_OBJSET_directory::ArrayLimit(PermSet& Perm) {};
void mu_1_OBJSET_directory::Limit(PermSet& Perm) {};
void mu_1_OBJSET_directory::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_Machines::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 17 ) && ( value() <= 19 ) )
      value(Perm.perm_mu_1_OBJSET_cache[Perm.in_mu_1_OBJSET_cache[i]][value()-17]+(0)); // value - base
  }
}
void mu_1_Machines::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 17 ) && ( value() <= 19 ) )
      {
        if (Perm.class_mu_1_OBJSET_cache[value()-17]==Perm.undefined_class_mu_1_OBJSET_cache) // value - base
          {
            // it has not been mapped to any particular value
            for (i=0; i<3; i++)
              if (Perm.class_mu_1_OBJSET_cache[i] == Perm.undefined_class_mu_1_OBJSET_cache && i!=value()-17)
                Perm.class_mu_1_OBJSET_cache[i]++;
            value(17 + Perm.undefined_class_mu_1_OBJSET_cache++);
          }
        else 
          {
            value(Perm.class_mu_1_OBJSET_cache[value()-17]+17);
          }
      }
  }
}
void mu_1_Machines::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Machines::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 17 ) && ( value() <= 19 ) )
      if (Perm.class_mu_1_OBJSET_cache[value()-17]==Perm.undefined_class_mu_1_OBJSET_cache) // value - base
        {
          // it has not been mapped to any particular value
          for (i=0; i<3; i++)
            if (Perm.class_mu_1_OBJSET_cache[i] == Perm.undefined_class_mu_1_OBJSET_cache && i!=value()-17)
              Perm.class_mu_1_OBJSET_cache[i]++;
          Perm.undefined_class_mu_1_OBJSET_cache++;
        }
  }
}
void mu_1_Machines::ArrayLimit(PermSet& Perm) {}
void mu_1_Machines::Limit(PermSet& Perm) {}
void mu_1_Machines::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for union type.\n"); };
void mu_1_ENTRY_cache::Permute(PermSet& Perm, int i)
{
};
void mu_1_ENTRY_cache::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1_ENTRY_cache::Canonicalize(PermSet& Perm)
{
};
void mu_1_ENTRY_cache::SimpleLimit(PermSet& Perm){}
void mu_1_ENTRY_cache::ArrayLimit(PermSet& Perm){}
void mu_1_ENTRY_cache::Limit(PermSet& Perm)
{
};
void mu_1_ENTRY_cache::MultisetLimit(PermSet& Perm)
{
};
void mu_1_ENTRY_directory::Permute(PermSet& Perm, int i)
{
  mu_owner.Permute(Perm,i);
};
void mu_1_ENTRY_directory::SimpleCanonicalize(PermSet& Perm)
{
  mu_owner.SimpleCanonicalize(Perm);
};
void mu_1_ENTRY_directory::Canonicalize(PermSet& Perm)
{
};
void mu_1_ENTRY_directory::SimpleLimit(PermSet& Perm)
{
  mu_owner.SimpleLimit(Perm);
};
void mu_1_ENTRY_directory::ArrayLimit(PermSet& Perm){}
void mu_1_ENTRY_directory::Limit(PermSet& Perm)
{
};
void mu_1_ENTRY_directory::MultisetLimit(PermSet& Perm)
{
};
void mu_1_Message::Permute(PermSet& Perm, int i)
{
  mu_src.Permute(Perm,i);
  mu_dst.Permute(Perm,i);
};
void mu_1_Message::SimpleCanonicalize(PermSet& Perm)
{
  mu_src.SimpleCanonicalize(Perm);
  mu_dst.SimpleCanonicalize(Perm);
};
void mu_1_Message::Canonicalize(PermSet& Perm)
{
};
void mu_1_Message::SimpleLimit(PermSet& Perm)
{
  mu_src.SimpleLimit(Perm);
  mu_dst.SimpleLimit(Perm);
};
void mu_1_Message::ArrayLimit(PermSet& Perm){}
void mu_1_Message::Limit(PermSet& Perm)
{
};
void mu_1_Message::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_0::Permute(PermSet& Perm, int i)
{
  static mu_1__type_0 temp("Permute_mu_1__type_0",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_0::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_0::Canonicalize(PermSet& Perm){};
void mu_1__type_0::SimpleLimit(PermSet& Perm){}
void mu_1__type_0::ArrayLimit(PermSet& Perm) {}
void mu_1__type_0::Limit(PermSet& Perm){}
void mu_1__type_0::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1_MACH_cache::Permute(PermSet& Perm, int i)
{
};
void mu_1_MACH_cache::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1_MACH_cache::Canonicalize(PermSet& Perm)
{
};
void mu_1_MACH_cache::SimpleLimit(PermSet& Perm){}
void mu_1_MACH_cache::ArrayLimit(PermSet& Perm){}
void mu_1_MACH_cache::Limit(PermSet& Perm)
{
};
void mu_1_MACH_cache::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_1::Permute(PermSet& Perm, int i)
{
  static mu_1__type_1 temp("Permute_mu_1__type_1",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_1::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<1; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1__type_1::Canonicalize(PermSet& Perm){};
void mu_1__type_1::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<1; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1__type_1::ArrayLimit(PermSet& Perm) {}
void mu_1__type_1::Limit(PermSet& Perm){}
void mu_1__type_1::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1_MACH_directory::Permute(PermSet& Perm, int i)
{
  mu_CL.Permute(Perm,i);
};
void mu_1_MACH_directory::SimpleCanonicalize(PermSet& Perm)
{
  mu_CL.SimpleCanonicalize(Perm);
};
void mu_1_MACH_directory::Canonicalize(PermSet& Perm)
{
};
void mu_1_MACH_directory::SimpleLimit(PermSet& Perm)
{
  mu_CL.SimpleLimit(Perm);
};
void mu_1_MACH_directory::ArrayLimit(PermSet& Perm){}
void mu_1_MACH_directory::Limit(PermSet& Perm)
{
};
void mu_1_MACH_directory::MultisetLimit(PermSet& Perm)
{
};
void mu_1_OBJ_cache::Permute(PermSet& Perm, int i)
{
  static mu_1_OBJ_cache temp("Permute_mu_1_OBJ_cache",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=17; j<=19; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_OBJSET_cache[Perm.in_mu_1_OBJSET_cache[i]][j-17]];};
void mu_1_OBJ_cache::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1_OBJ_cache::Canonicalize(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_OBJSET_cache;
  int compare;
  static mu_1_MACH_cache value[3];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_OBJSET_cache[3];
  bool pos_mu_1_OBJSET_cache[3][3];
  // range mapping
  int start;
  int class_size;
  int size_mu_1_OBJSET_cache[3];
  int start_mu_1_OBJSET_cache[3];
  // canonicalization
  static mu_1_OBJ_cache temp;
  // sorting mu_1_OBJSET_cache
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cache())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_OBJSET_cache[i][j]=FALSE;
      count_mu_1_OBJSET_cache = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_OBJSET_cache; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+17]);
              if (compare==0)
                {
                  pos_mu_1_OBJSET_cache[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_OBJSET_cache; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<3; z++)
                        pos_mu_1_OBJSET_cache[k][z] = pos_mu_1_OBJSET_cache[k-1][z];
                    }
                  value[j] = (*this)[i+17];
                  for (z=0; z<3; z++)
                    pos_mu_1_OBJSET_cache[j][z] = FALSE;
                  pos_mu_1_OBJSET_cache[j][i] = TRUE;
                  count_mu_1_OBJSET_cache++;
                  break;
                }
            }
          if (j==count_mu_1_OBJSET_cache)
            {
              value[j] = (*this)[i+17];
              for (z=0; z<3; z++)
                pos_mu_1_OBJSET_cache[j][z] = FALSE;
              pos_mu_1_OBJSET_cache[j][i] = TRUE;
              count_mu_1_OBJSET_cache++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cache() && count_mu_1_OBJSET_cache>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_OBJSET_cache; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_OBJSET_cache[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_OBJSET_cache[i][k] && Perm.class_mu_1_OBJSET_cache[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_OBJSET_cache[k] = TRUE;
                    pos_mu_1_OBJSET_cache[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_OBJSET_cache[k] == j && !goodset_mu_1_OBJSET_cache[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_OBJSET_cache[k]>j
                            || ( Perm.class_mu_1_OBJSET_cache[k] == j && !goodset_mu_1_OBJSET_cache[k] ) )
                          Perm.class_mu_1_OBJSET_cache[k]++;
                      Perm.undefined_class_mu_1_OBJSET_cache++;
                    }
                }
            }
        }
    }
  if (Perm.MTO_class_mu_1_OBJSET_cache())
    {

      // setup range for maping
      start = 0;
      for (j=0; j<=Perm.undefined_class_mu_1_OBJSET_cache; j++) // class number
        {
          class_size = 0;
          for (k=0; k<3; k++) // step through class[k]
            if (Perm.class_mu_1_OBJSET_cache[k]==j)
              class_size++;
          for (k=0; k<3; k++) // step through class[k]
            if (Perm.class_mu_1_OBJSET_cache[k]==j)
              {
                size_mu_1_OBJSET_cache[k] = class_size;
                start_mu_1_OBJSET_cache[k] = start;
              }
          start+=class_size;
        }

      // canonicalize
      temp = *this;
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
         if (i >=start_mu_1_OBJSET_cache[j] 
             && i < start_mu_1_OBJSET_cache[j] + size_mu_1_OBJSET_cache[j])
           {
             array[i+0] = temp[j+17];
             break;
           }
    }
  else
    {

      // fast canonicalize
      temp = *this;
      for (j=0; j<3; j++)
        array[Perm.class_mu_1_OBJSET_cache[j]+0] = temp[j+17];
    }
}
void mu_1_OBJ_cache::SimpleLimit(PermSet& Perm){}
void mu_1_OBJ_cache::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_OBJSET_cache;
  int compare;
  static mu_1_MACH_cache value[3];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_OBJSET_cache[3];
  bool pos_mu_1_OBJSET_cache[3][3];
  // sorting mu_1_OBJSET_cache
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cache())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_OBJSET_cache[i][j]=FALSE;
      count_mu_1_OBJSET_cache = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_OBJSET_cache; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+17]);
              if (compare==0)
                {
                  pos_mu_1_OBJSET_cache[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_OBJSET_cache; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<3; z++)
                        pos_mu_1_OBJSET_cache[k][z] = pos_mu_1_OBJSET_cache[k-1][z];
                    }
                  value[j] = (*this)[i+17];
                  for (z=0; z<3; z++)
                    pos_mu_1_OBJSET_cache[j][z] = FALSE;
                  pos_mu_1_OBJSET_cache[j][i] = TRUE;
                  count_mu_1_OBJSET_cache++;
                  break;
                }
            }
          if (j==count_mu_1_OBJSET_cache)
            {
              value[j] = (*this)[i+17];
              for (z=0; z<3; z++)
                pos_mu_1_OBJSET_cache[j][z] = FALSE;
              pos_mu_1_OBJSET_cache[j][i] = TRUE;
              count_mu_1_OBJSET_cache++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cache() && count_mu_1_OBJSET_cache>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_OBJSET_cache; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_OBJSET_cache[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_OBJSET_cache[i][k] && Perm.class_mu_1_OBJSET_cache[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_OBJSET_cache[k] = TRUE;
                    pos_mu_1_OBJSET_cache[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_OBJSET_cache[k] == j && !goodset_mu_1_OBJSET_cache[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_OBJSET_cache[k]>j
                            || ( Perm.class_mu_1_OBJSET_cache[k] == j && !goodset_mu_1_OBJSET_cache[k] ) )
                          Perm.class_mu_1_OBJSET_cache[k]++;
                      Perm.undefined_class_mu_1_OBJSET_cache++;
                    }
                }
            }
        }
    }
}
void mu_1_OBJ_cache::Limit(PermSet& Perm){}
void mu_1_OBJ_cache::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1_OBJ_directory::Permute(PermSet& Perm, int i)
{
  static mu_1_OBJ_directory temp("Permute_mu_1_OBJ_directory",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1_OBJ_directory::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<1; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1_OBJ_directory::Canonicalize(PermSet& Perm){};
void mu_1_OBJ_directory::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<1; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1_OBJ_directory::ArrayLimit(PermSet& Perm) {}
void mu_1_OBJ_directory::Limit(PermSet& Perm){}
void mu_1_OBJ_directory::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu__subrange_21::Permute(PermSet& Perm, int i) {};
void mu__subrange_21::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_21::Canonicalize(PermSet& Perm) {};
void mu__subrange_21::SimpleLimit(PermSet& Perm) {};
void mu__subrange_21::ArrayLimit(PermSet& Perm) {};
void mu__subrange_21::Limit(PermSet& Perm) {};
void mu__subrange_21::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_2::Permute(PermSet& Perm, int i)
{
  static mu_1__type_2 temp("Permute_mu_1__type_2",-1);
  int j;
  for (j=0; j<12; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_2::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<12; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1__type_2::Canonicalize(PermSet& Perm){};
void mu_1__type_2::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<12; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1__type_2::ArrayLimit(PermSet& Perm) {}
void mu_1__type_2::Limit(PermSet& Perm){}
void mu_1__type_2::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1_OBJ_Ordered::Permute(PermSet& Perm, int i)
{
  static mu_1_OBJ_Ordered temp("Permute_mu_1_OBJ_Ordered",-1);
  int j;
  for (j=0; j<4; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=17; j<=19; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_OBJSET_cache[Perm.in_mu_1_OBJSET_cache[i]][j-17]];
};
void mu_1_OBJ_Ordered::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1_OBJ_Ordered::Canonicalize(PermSet& Perm){};
void mu_1_OBJ_Ordered::SimpleLimit(PermSet& Perm){}
void mu_1_OBJ_Ordered::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int compare;
  static mu_1__type_2 value[4];
  // limit
  bool exists;
  bool split;
  int count_mu_1_OBJSET_cache;
  bool pos_mu_1_OBJSET_cache[3][3];
  bool goodset_mu_1_OBJSET_cache[3];
  // sorting mu_1_OBJSET_cache
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cache())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_OBJSET_cache[i][j]=FALSE;
      count_mu_1_OBJSET_cache = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_OBJSET_cache; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+17]);
              if (compare==0)
                {
                  pos_mu_1_OBJSET_cache[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_OBJSET_cache; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<3; z++)
                        pos_mu_1_OBJSET_cache[k][z] = pos_mu_1_OBJSET_cache[k-1][z];
                    }
                  value[j] = (*this)[i+17];
                  for (z=0; z<3; z++)
                    pos_mu_1_OBJSET_cache[j][z] = FALSE;
                  pos_mu_1_OBJSET_cache[j][i] = TRUE;
                  count_mu_1_OBJSET_cache++;
                  break;
                }
            }
          if (j==count_mu_1_OBJSET_cache)
            {
              value[j] = (*this)[i+17];
              for (z=0; z<3; z++)
                pos_mu_1_OBJSET_cache[j][z] = FALSE;
              pos_mu_1_OBJSET_cache[j][i] = TRUE;
              count_mu_1_OBJSET_cache++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cache() && count_mu_1_OBJSET_cache>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_OBJSET_cache; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_OBJSET_cache[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_OBJSET_cache[i][k] && Perm.class_mu_1_OBJSET_cache[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_OBJSET_cache[k] = TRUE;
                    pos_mu_1_OBJSET_cache[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_OBJSET_cache[k] == j && !goodset_mu_1_OBJSET_cache[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_OBJSET_cache[k]>j
                            || ( Perm.class_mu_1_OBJSET_cache[k] == j && !goodset_mu_1_OBJSET_cache[k] ) )
                          Perm.class_mu_1_OBJSET_cache[k]++;
                      Perm.undefined_class_mu_1_OBJSET_cache++;
                    }
                }
            }
        }
    }
}
void mu_1_OBJ_Ordered::Limit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1__type_2 value[4];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_OBJSET_cache, oldcount_mu_1_OBJSET_cache;
  bool pos_mu_1_OBJSET_cache[3][3];
  bool goodset_mu_1_OBJSET_cache[3];
  // initializing pos array
  for (i=0; i<3; i++)
    for (j=0; j<3; j++)
      pos_mu_1_OBJSET_cache[i][j]=FALSE;
  count_mu_1_OBJSET_cache = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<3; i++)
       if (Perm.class_mu_1_OBJSET_cache[i] == count_mu_1_OBJSET_cache)
         {
           pos_mu_1_OBJSET_cache[count_mu_1_OBJSET_cache][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_OBJSET_cache++;
      else break;
    }
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 11; i0++)
  {

  // refinement -- check selfloop
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cache() && count_mu_1_OBJSET_cache<3)
    {
      exists = FALSE;
      split = FALSE;
      // if there exists both self loop and non-self loop
      for (k=0; k<3; k++) // step through class
        if ((*this)[k+17][i0].mu_src.isundefined()
            ||(*this)[k+17][i0].mu_src!=k+17)
          exists = TRUE;
        else
          split = TRUE;
      if (exists && split)
        {
          for (i=0; i<count_mu_1_OBJSET_cache; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_OBJSET_cache[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_OBJSET_cache[i][k] 
                    && !(*this)[k+17][i0].mu_src.isundefined()
                    && (*this)[k+17][i0].mu_src==k+17)
                  {
                    exists = TRUE;
                    goodset_mu_1_OBJSET_cache[k] = TRUE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( pos_mu_1_OBJSET_cache[i][k] && !goodset_mu_1_OBJSET_cache[k] ) 
                          split= TRUE;
                  if (split)
                    {
                      for (j=count_mu_1_OBJSET_cache; j>i; j--)
                        for (k=0; k<3; k++)
                          pos_mu_1_OBJSET_cache[j][k] = pos_mu_1_OBJSET_cache[j-1][k];
                      for (k=0; k<3; k++)
                        {
                          if (pos_mu_1_OBJSET_cache[i][k] && !goodset_mu_1_OBJSET_cache[k])
                            pos_mu_1_OBJSET_cache[i][k] = FALSE;
                          if (pos_mu_1_OBJSET_cache[i+1][k] && goodset_mu_1_OBJSET_cache[k])
                            pos_mu_1_OBJSET_cache[i+1][k] = FALSE;
                        }
                      count_mu_1_OBJSET_cache++; i++;
                    }
                }
            }
        }
    }

  // refinement -- check selfloop
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cache() && count_mu_1_OBJSET_cache<3)
    {
      exists = FALSE;
      split = FALSE;
      // if there exists both self loop and non-self loop
      for (k=0; k<3; k++) // step through class
        if ((*this)[k+17][i0].mu_dst.isundefined()
            ||(*this)[k+17][i0].mu_dst!=k+17)
          exists = TRUE;
        else
          split = TRUE;
      if (exists && split)
        {
          for (i=0; i<count_mu_1_OBJSET_cache; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_OBJSET_cache[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_OBJSET_cache[i][k] 
                    && !(*this)[k+17][i0].mu_dst.isundefined()
                    && (*this)[k+17][i0].mu_dst==k+17)
                  {
                    exists = TRUE;
                    goodset_mu_1_OBJSET_cache[k] = TRUE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( pos_mu_1_OBJSET_cache[i][k] && !goodset_mu_1_OBJSET_cache[k] ) 
                          split= TRUE;
                  if (split)
                    {
                      for (j=count_mu_1_OBJSET_cache; j>i; j--)
                        for (k=0; k<3; k++)
                          pos_mu_1_OBJSET_cache[j][k] = pos_mu_1_OBJSET_cache[j-1][k];
                      for (k=0; k<3; k++)
                        {
                          if (pos_mu_1_OBJSET_cache[i][k] && !goodset_mu_1_OBJSET_cache[k])
                            pos_mu_1_OBJSET_cache[i][k] = FALSE;
                          if (pos_mu_1_OBJSET_cache[i+1][k] && goodset_mu_1_OBJSET_cache[k])
                            pos_mu_1_OBJSET_cache[i+1][k] = FALSE;
                        }
                      count_mu_1_OBJSET_cache++; i++;
                    }
                }
            }
        }
    }
  }

  // refinement -- checking priority in general
  while_guard = FALSE;
  while_guard = while_guard || (Perm.MTO_class_mu_1_OBJSET_cache() && count_mu_1_OBJSET_cache<3);
  while ( while_guard )
    {
      oldcount_mu_1_OBJSET_cache = count_mu_1_OBJSET_cache;
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 11; i0++)
  {

      // refinement -- graph structure for a single scalarset
      //               as in array S1 of S1
      // only if there is more than 1 permutation in class
      if (Perm.MTO_class_mu_1_OBJSET_cache() && count_mu_1_OBJSET_cache<3)
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<3; k++) // step through class
            if (!(*this)[k+17][i0].mu_src.isundefined()
                &&(*this)[k+17][i0].mu_src!=k+17
                &&(*this)[k+17][i0].mu_src>=17
                &&(*this)[k+17][i0].mu_src<=19)
              exists = TRUE;
          if (exists)
            {
              for (i=0; i<count_mu_1_OBJSET_cache; i++) // for value priority
                {
                  for (j=0; j<count_mu_1_OBJSET_cache; j++) // for value priority
                    {
                      exists = FALSE;
                      for (k=0; k<3; k++) // step through class
                        goodset_mu_1_OBJSET_cache[k] = FALSE;
                      for (k=0; k<3; k++) // step through class
                        if (pos_mu_1_OBJSET_cache[i][k] 
                            && !(*this)[k+17][i0].mu_src.isundefined()
                            && (*this)[k+17][i0].mu_src!=k+17
                            && (*this)[k+17][i0].mu_src>=17
                            && (*this)[k+17][i0].mu_src<=19
                            && pos_mu_1_OBJSET_cache[j][(*this)[k+17][i0].mu_src-17])
                          {
                            exists = TRUE;
                            goodset_mu_1_OBJSET_cache[k] = TRUE;
                          }
                      if (exists)
                        {
                          split=FALSE;
                          for (k=0; k<3; k++)
                            if ( pos_mu_1_OBJSET_cache[i][k] && !goodset_mu_1_OBJSET_cache[k] ) 
                              split= TRUE;
                          if (split)
                            {
                              for (j=count_mu_1_OBJSET_cache; j>i; j--)
                                for (k=0; k<3; k++)
                                  pos_mu_1_OBJSET_cache[j][k] = pos_mu_1_OBJSET_cache[j-1][k];
                              for (k=0; k<3; k++)
                                {
                                  if (pos_mu_1_OBJSET_cache[i][k] && !goodset_mu_1_OBJSET_cache[k])
                                    pos_mu_1_OBJSET_cache[i][k] = FALSE;
                                  if (pos_mu_1_OBJSET_cache[i+1][k] && goodset_mu_1_OBJSET_cache[k])
                                    pos_mu_1_OBJSET_cache[i+1][k] = FALSE;                  
                                }
                              count_mu_1_OBJSET_cache++;
                            }
                        }
                    }
                }
            }
        }

      // refinement -- graph structure for a single scalarset
      //               as in array S1 of S1
      // only if there is more than 1 permutation in class
      if (Perm.MTO_class_mu_1_OBJSET_cache() && count_mu_1_OBJSET_cache<3)
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<3; k++) // step through class
            if (!(*this)[k+17][i0].mu_dst.isundefined()
                &&(*this)[k+17][i0].mu_dst!=k+17
                &&(*this)[k+17][i0].mu_dst>=17
                &&(*this)[k+17][i0].mu_dst<=19)
              exists = TRUE;
          if (exists)
            {
              for (i=0; i<count_mu_1_OBJSET_cache; i++) // for value priority
                {
                  for (j=0; j<count_mu_1_OBJSET_cache; j++) // for value priority
                    {
                      exists = FALSE;
                      for (k=0; k<3; k++) // step through class
                        goodset_mu_1_OBJSET_cache[k] = FALSE;
                      for (k=0; k<3; k++) // step through class
                        if (pos_mu_1_OBJSET_cache[i][k] 
                            && !(*this)[k+17][i0].mu_dst.isundefined()
                            && (*this)[k+17][i0].mu_dst!=k+17
                            && (*this)[k+17][i0].mu_dst>=17
                            && (*this)[k+17][i0].mu_dst<=19
                            && pos_mu_1_OBJSET_cache[j][(*this)[k+17][i0].mu_dst-17])
                          {
                            exists = TRUE;
                            goodset_mu_1_OBJSET_cache[k] = TRUE;
                          }
                      if (exists)
                        {
                          split=FALSE;
                          for (k=0; k<3; k++)
                            if ( pos_mu_1_OBJSET_cache[i][k] && !goodset_mu_1_OBJSET_cache[k] ) 
                              split= TRUE;
                          if (split)
                            {
                              for (j=count_mu_1_OBJSET_cache; j>i; j--)
                                for (k=0; k<3; k++)
                                  pos_mu_1_OBJSET_cache[j][k] = pos_mu_1_OBJSET_cache[j-1][k];
                              for (k=0; k<3; k++)
                                {
                                  if (pos_mu_1_OBJSET_cache[i][k] && !goodset_mu_1_OBJSET_cache[k])
                                    pos_mu_1_OBJSET_cache[i][k] = FALSE;
                                  if (pos_mu_1_OBJSET_cache[i+1][k] && goodset_mu_1_OBJSET_cache[k])
                                    pos_mu_1_OBJSET_cache[i+1][k] = FALSE;                  
                                }
                              count_mu_1_OBJSET_cache++;
                            }
                        }
                    }
                }
            }
        }
  }
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 11; i0++)
  {
  }
      while_guard = FALSE;
      while_guard = while_guard || (oldcount_mu_1_OBJSET_cache!=count_mu_1_OBJSET_cache);
      while_guard_temp = while_guard;
      while_guard = FALSE;
      while_guard = while_guard || count_mu_1_OBJSET_cache<3;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_OBJSET_cache())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          if (pos_mu_1_OBJSET_cache[i][j])
            Perm.class_mu_1_OBJSET_cache[j] = i;
      Perm.undefined_class_mu_1_OBJSET_cache=0;
      for (j=0; j<3; j++)
        if (Perm.class_mu_1_OBJSET_cache[j]>Perm.undefined_class_mu_1_OBJSET_cache)
          Perm.undefined_class_mu_1_OBJSET_cache=Perm.class_mu_1_OBJSET_cache[j];
    }
}
void mu_1_OBJ_Ordered::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_3::Permute(PermSet& Perm, int i) {};
void mu_1__type_3::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_3::Canonicalize(PermSet& Perm) {};
void mu_1__type_3::SimpleLimit(PermSet& Perm) {};
void mu_1__type_3::ArrayLimit(PermSet& Perm) {};
void mu_1__type_3::Limit(PermSet& Perm) {};
void mu_1__type_3::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_OBJ_Orderedcnt::Permute(PermSet& Perm, int i)
{
  static mu_1_OBJ_Orderedcnt temp("Permute_mu_1_OBJ_Orderedcnt",-1);
  int j;
  for (j=0; j<4; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=17; j<=19; j++)
      (*this)[j].value(temp[Perm.revperm_mu_1_OBJSET_cache[Perm.in_mu_1_OBJSET_cache[i]][j-17]].value());
};
void mu_1_OBJ_Orderedcnt::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1_OBJ_Orderedcnt::Canonicalize(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  static mu_1__type_3 value[4];
  int compare;
  // limit
  bool exists;
  bool split;
  // range mapping
  int start;
  int class_size;
  // canonicalization
  static mu_1_OBJ_Orderedcnt temp;
  int count_mu_1_OBJSET_cache;
  bool pos_mu_1_OBJSET_cache[3][3];
  bool goodset_mu_1_OBJSET_cache[3];
  int size_mu_1_OBJSET_cache[3];
  int start_mu_1_OBJSET_cache[3];
  // sorting mu_1_OBJSET_cache
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cache())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_OBJSET_cache[i][j]=FALSE;
      count_mu_1_OBJSET_cache = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_OBJSET_cache; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+17]);
              if (compare==0)
                {
                  pos_mu_1_OBJSET_cache[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_OBJSET_cache; k>j; k--)
                    {
                      value[k].value(value[k-1].value());
                      for (z=0; z<3; z++)
                        pos_mu_1_OBJSET_cache[k][z] = pos_mu_1_OBJSET_cache[k-1][z];
                    }
                  value[j].value((*this)[i+17].value());
                  for (z=0; z<3; z++)
                    pos_mu_1_OBJSET_cache[j][z] = FALSE;
                  pos_mu_1_OBJSET_cache[j][i] = TRUE;
                  count_mu_1_OBJSET_cache++;
                  break;
                }
            }
          if (j==count_mu_1_OBJSET_cache)
            {
                value[j].value((*this)[i+17].value());
              for (z=0; z<3; z++)
                pos_mu_1_OBJSET_cache[j][z] = FALSE;
              pos_mu_1_OBJSET_cache[j][i] = TRUE;
              count_mu_1_OBJSET_cache++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cache() && count_mu_1_OBJSET_cache>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_OBJSET_cache; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_OBJSET_cache[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_OBJSET_cache[i][k] && Perm.class_mu_1_OBJSET_cache[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_OBJSET_cache[k] = TRUE;
                    pos_mu_1_OBJSET_cache[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_OBJSET_cache[k] == j && !goodset_mu_1_OBJSET_cache[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_OBJSET_cache[k]>j
                            || ( Perm.class_mu_1_OBJSET_cache[k] == j && !goodset_mu_1_OBJSET_cache[k] ) )
                          Perm.class_mu_1_OBJSET_cache[k]++;
                      Perm.undefined_class_mu_1_OBJSET_cache++;
                    }
                }
            }
        }
    }
  if (Perm.MTO_class_mu_1_OBJSET_cache())
    {

      // setup range for maping
      start = 0;
      for (j=0; j<=Perm.undefined_class_mu_1_OBJSET_cache; j++) // class number
        {
          class_size = 0;
          for (k=0; k<3; k++) // step through class[k]
            if (Perm.class_mu_1_OBJSET_cache[k]==j)
              class_size++;
          for (k=0; k<3; k++) // step through class[k]
            if (Perm.class_mu_1_OBJSET_cache[k]==j)
              {
                size_mu_1_OBJSET_cache[k] = class_size;
                start_mu_1_OBJSET_cache[k] = start;
              }
          start+=class_size;
        }

      // canonicalize
      temp = *this;
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
         if (i >=start_mu_1_OBJSET_cache[j] 
             && i < start_mu_1_OBJSET_cache[j] + size_mu_1_OBJSET_cache[j])
           {
             array[i+0].value(temp[j+17].value());
             break;
           }
    }
  else
    {

      // fast canonicalize
      temp = *this;
      for (j=0; j<3; j++)
        array[Perm.class_mu_1_OBJSET_cache[j]+0].value(temp[j+17].value());
    }
}
void mu_1_OBJ_Orderedcnt::SimpleLimit(PermSet& Perm){}
void mu_1_OBJ_Orderedcnt::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int compare;
  static mu_1__type_3 value[4];
  // limit
  bool exists;
  bool split;
  int count_mu_1_OBJSET_cache;
  bool pos_mu_1_OBJSET_cache[3][3];
  bool goodset_mu_1_OBJSET_cache[3];
  // sorting mu_1_OBJSET_cache
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cache())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_OBJSET_cache[i][j]=FALSE;
      count_mu_1_OBJSET_cache = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_OBJSET_cache; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+17]);
              if (compare==0)
                {
                  pos_mu_1_OBJSET_cache[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_OBJSET_cache; k>j; k--)
                    {
                      value[k].value(value[k-1].value());
                      for (z=0; z<3; z++)
                        pos_mu_1_OBJSET_cache[k][z] = pos_mu_1_OBJSET_cache[k-1][z];
                    }
                  value[j].value((*this)[i+17].value());
                  for (z=0; z<3; z++)
                    pos_mu_1_OBJSET_cache[j][z] = FALSE;
                  pos_mu_1_OBJSET_cache[j][i] = TRUE;
                  count_mu_1_OBJSET_cache++;
                  break;
                }
            }
          if (j==count_mu_1_OBJSET_cache)
            {
                value[j].value((*this)[i+17].value());
              for (z=0; z<3; z++)
                pos_mu_1_OBJSET_cache[j][z] = FALSE;
              pos_mu_1_OBJSET_cache[j][i] = TRUE;
              count_mu_1_OBJSET_cache++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cache() && count_mu_1_OBJSET_cache>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_OBJSET_cache; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_OBJSET_cache[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_OBJSET_cache[i][k] && Perm.class_mu_1_OBJSET_cache[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_OBJSET_cache[k] = TRUE;
                    pos_mu_1_OBJSET_cache[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_OBJSET_cache[k] == j && !goodset_mu_1_OBJSET_cache[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_OBJSET_cache[k]>j
                            || ( Perm.class_mu_1_OBJSET_cache[k] == j && !goodset_mu_1_OBJSET_cache[k] ) )
                          Perm.class_mu_1_OBJSET_cache[k]++;
                      Perm.undefined_class_mu_1_OBJSET_cache++;
                    }
                }
            }
        }
    }
}
void mu_1_OBJ_Orderedcnt::Limit(PermSet& Perm){}
void mu_1_OBJ_Orderedcnt::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_4::Permute(PermSet& Perm, int i)
{
  static mu_1__type_4 temp("Permute_mu_1__type_4",-1);
  int j;
  for (j=0; j<12; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_4::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: calling SimpleCanonicalize for a multiset.\n"); };
void mu_1__type_4::Canonicalize(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_4::SimpleLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_4::ArrayLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_4::Limit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_4::MultisetLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_Message value[12];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_OBJSET_cache, oldcount_mu_1_OBJSET_cache;
  bool pos_mu_1_OBJSET_cache[3][3];
  bool goodset_mu_1_OBJSET_cache[3];
  int count_multisetindex, oldcount_multisetindex;
  bool pos_multisetindex[12][12];
  bool goodset_multisetindex[12];
  mu_1_Message temp;

  // compact
  for (i = 0, j = 0; i < 12; i++)
    if (valid[i].value())
      {
        if (j!=i)
          array[j++] = array[i];
        else
          j++;
      }
  if (j != current_size) current_size = j;
  for (i = j; i < 12; i++)
    array[i].undefine();
  for (i = 0; i < j; i++)
    valid[i].value(TRUE);
  for (i = j; i < 12; i++)
    valid[i].value(FALSE);

  // bubble sort
  for (i = 0; i < current_size; i++)
    for (j = i+1; j < current_size; j++)
      if (CompareWeight(array[i],array[j])>0)
        {
          temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
  // initializing pos array
    for (i=0; i<current_size; i++)
      for (j=0; j<current_size; j++)
        pos_multisetindex[i][j]=FALSE;
    count_multisetindex = 1;
    pos_multisetindex[0][0] = TRUE;
    for (i = 1, j = 0 ; i < current_size; i++)
      if (CompareWeight(array[i-1],array[i])==0)
        pos_multisetindex[j][i] = TRUE;
      else
        { count_multisetindex++; pos_multisetindex[++j][i] = TRUE; }
  if (current_size == 1)
    {
      array[0].SimpleLimit(Perm);
    }
  else
    {

  // initializing pos array
  for (i=0; i<3; i++)
    for (j=0; j<3; j++)
      pos_mu_1_OBJSET_cache[i][j]=FALSE;
  count_mu_1_OBJSET_cache = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<3; i++)
       if (Perm.class_mu_1_OBJSET_cache[i] == count_mu_1_OBJSET_cache)
         {
           pos_mu_1_OBJSET_cache[count_mu_1_OBJSET_cache][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_OBJSET_cache++;
      else break;
    }

  // refinement -- checking priority in general
  while_guard = (count_multisetindex < current_size);
  while_guard = while_guard || (Perm.MTO_class_mu_1_OBJSET_cache() && count_mu_1_OBJSET_cache<3);
  while ( while_guard )
    {
      oldcount_multisetindex = count_multisetindex;
      oldcount_mu_1_OBJSET_cache = count_mu_1_OBJSET_cache;

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_OBJSET_cache() && count_mu_1_OBJSET_cache<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].mu_src.isundefined())
                && (*this)[k].mu_src>=17
                && (*this)[k].mu_src<=19)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_OBJSET_cache; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_OBJSET_cache[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_src.isundefined()
                          && (*this)[k].mu_src>=17
                          && (*this)[k].mu_src<=19
                          && pos_mu_1_OBJSET_cache[j][(*this)[k].mu_src-17])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_OBJSET_cache[(*this)[k].mu_src-17] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_OBJSET_cache[j][k] && !goodset_mu_1_OBJSET_cache[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_OBJSET_cache; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_OBJSET_cache[z][k] = pos_mu_1_OBJSET_cache[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_OBJSET_cache[j][k] && !goodset_mu_1_OBJSET_cache[k])
                                  pos_mu_1_OBJSET_cache[j][k] = FALSE;
                                if (pos_mu_1_OBJSET_cache[j+1][k] && goodset_mu_1_OBJSET_cache[k])
                                  pos_mu_1_OBJSET_cache[j+1][k] = FALSE;
                              }
                            count_mu_1_OBJSET_cache++;
                          }
                      }
                  }
            }
        }

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_OBJSET_cache() && count_mu_1_OBJSET_cache<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].mu_dst.isundefined())
                && (*this)[k].mu_dst>=17
                && (*this)[k].mu_dst<=19)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_OBJSET_cache; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_OBJSET_cache[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_dst.isundefined()
                          && (*this)[k].mu_dst>=17
                          && (*this)[k].mu_dst<=19
                          && pos_mu_1_OBJSET_cache[j][(*this)[k].mu_dst-17])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_OBJSET_cache[(*this)[k].mu_dst-17] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_OBJSET_cache[j][k] && !goodset_mu_1_OBJSET_cache[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_OBJSET_cache; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_OBJSET_cache[z][k] = pos_mu_1_OBJSET_cache[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_OBJSET_cache[j][k] && !goodset_mu_1_OBJSET_cache[k])
                                  pos_mu_1_OBJSET_cache[j][k] = FALSE;
                                if (pos_mu_1_OBJSET_cache[j+1][k] && goodset_mu_1_OBJSET_cache[k])
                                  pos_mu_1_OBJSET_cache[j+1][k] = FALSE;
                              }
                            count_mu_1_OBJSET_cache++;
                          }
                      }
                  }
            }
        }
      while_guard = oldcount_multisetindex!=count_multisetindex;
      while_guard = while_guard || (oldcount_mu_1_OBJSET_cache!=count_mu_1_OBJSET_cache);
      while_guard_temp = while_guard;
      while_guard = (count_multisetindex < current_size);
      while_guard = while_guard || count_mu_1_OBJSET_cache<3;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_OBJSET_cache())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          if (pos_mu_1_OBJSET_cache[i][j])
            Perm.class_mu_1_OBJSET_cache[j] = i;
      Perm.undefined_class_mu_1_OBJSET_cache=0;
      for (j=0; j<3; j++)
        if (Perm.class_mu_1_OBJSET_cache[j]>Perm.undefined_class_mu_1_OBJSET_cache)
          Perm.undefined_class_mu_1_OBJSET_cache=Perm.class_mu_1_OBJSET_cache[j];
    }
  }
}
void mu_1_OBJ_Unordered::Permute(PermSet& Perm, int i)
{
  static mu_1_OBJ_Unordered temp("Permute_mu_1_OBJ_Unordered",-1);
  int j;
  for (j=0; j<4; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=17; j<=19; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_OBJSET_cache[Perm.in_mu_1_OBJSET_cache[i]][j-17]];
};
void mu_1_OBJ_Unordered::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1_OBJ_Unordered::Canonicalize(PermSet& Perm){};
void mu_1_OBJ_Unordered::SimpleLimit(PermSet& Perm){}
void mu_1_OBJ_Unordered::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int compare;
  static mu_1__type_4 value[4];
  // limit
  bool exists;
  bool split;
  int count_mu_1_OBJSET_cache;
  bool pos_mu_1_OBJSET_cache[3][3];
  bool goodset_mu_1_OBJSET_cache[3];
  // sorting mu_1_OBJSET_cache
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cache())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_OBJSET_cache[i][j]=FALSE;
      count_mu_1_OBJSET_cache = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_OBJSET_cache; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+17]);
              if (compare==0)
                {
                  pos_mu_1_OBJSET_cache[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_OBJSET_cache; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<3; z++)
                        pos_mu_1_OBJSET_cache[k][z] = pos_mu_1_OBJSET_cache[k-1][z];
                    }
                  value[j] = (*this)[i+17];
                  for (z=0; z<3; z++)
                    pos_mu_1_OBJSET_cache[j][z] = FALSE;
                  pos_mu_1_OBJSET_cache[j][i] = TRUE;
                  count_mu_1_OBJSET_cache++;
                  break;
                }
            }
          if (j==count_mu_1_OBJSET_cache)
            {
              value[j] = (*this)[i+17];
              for (z=0; z<3; z++)
                pos_mu_1_OBJSET_cache[j][z] = FALSE;
              pos_mu_1_OBJSET_cache[j][i] = TRUE;
              count_mu_1_OBJSET_cache++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cache() && count_mu_1_OBJSET_cache>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_OBJSET_cache; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_OBJSET_cache[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_OBJSET_cache[i][k] && Perm.class_mu_1_OBJSET_cache[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_OBJSET_cache[k] = TRUE;
                    pos_mu_1_OBJSET_cache[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_OBJSET_cache[k] == j && !goodset_mu_1_OBJSET_cache[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_OBJSET_cache[k]>j
                            || ( Perm.class_mu_1_OBJSET_cache[k] == j && !goodset_mu_1_OBJSET_cache[k] ) )
                          Perm.class_mu_1_OBJSET_cache[k]++;
                      Perm.undefined_class_mu_1_OBJSET_cache++;
                    }
                }
            }
        }
    }
}
void mu_1_OBJ_Unordered::Limit(PermSet& Perm){}
void mu_1_OBJ_Unordered::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1_CL_MUTEX::Permute(PermSet& Perm, int i)
{
  static mu_1_CL_MUTEX temp("Permute_mu_1_CL_MUTEX",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1_CL_MUTEX::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1_CL_MUTEX::Canonicalize(PermSet& Perm){};
void mu_1_CL_MUTEX::SimpleLimit(PermSet& Perm){}
void mu_1_CL_MUTEX::ArrayLimit(PermSet& Perm) {}
void mu_1_CL_MUTEX::Limit(PermSet& Perm){}
void mu_1_CL_MUTEX::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };

/********************
 Auxiliary function for error trace printing
 ********************/
bool match(state* ns, StatePtr p)
{
  int i;
  static PermSet Perm;
  static state temp;
  StateCopy(&temp, ns);
  if (args->symmetry_reduction.value)
    {
      if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize
         || args->sym_alg.mode == argsym_alg::Heuristic_Fast_Canonicalize) {
        Perm.ResetToExplicit();
        for (i=0; i<Perm.count; i++)
          if (Perm.In(i))
            {
              if (ns != workingstate)
                  StateCopy(workingstate, ns);
              
              mu_cl_mut.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_cl_mut.MultisetSort();
              mu_i_directory.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_i_directory.MultisetSort();
              mu_cnt_fwd.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_cnt_fwd.MultisetSort();
              mu_i_cache.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_i_cache.MultisetSort();
              mu_fwd.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_fwd.MultisetSort();
              mu_req.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_req.MultisetSort();
              mu_resp.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_resp.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
      else {
        Perm.ResetToSimple();
        Perm.SimpleToOne();
        if (ns != workingstate)
          StateCopy(workingstate, ns);

          mu_cl_mut.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_cl_mut.MultisetSort();
          mu_i_directory.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_i_directory.MultisetSort();
          mu_cnt_fwd.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_cnt_fwd.MultisetSort();
          mu_i_cache.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_i_cache.MultisetSort();
          mu_fwd.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_fwd.MultisetSort();
          mu_req.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_req.MultisetSort();
          mu_resp.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_resp.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_cl_mut.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_cl_mut.MultisetSort();
              mu_i_directory.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_i_directory.MultisetSort();
              mu_cnt_fwd.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_cnt_fwd.MultisetSort();
              mu_i_cache.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_i_cache.MultisetSort();
              mu_fwd.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_fwd.MultisetSort();
              mu_req.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_req.MultisetSort();
              mu_resp.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_resp.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
    }
  if (!args->symmetry_reduction.value
      && args->multiset_reduction.value)
    {
      if (ns != workingstate)
          StateCopy(workingstate, ns);
      mu_cl_mut.MultisetSort();
      mu_i_directory.MultisetSort();
      mu_cnt_fwd.MultisetSort();
      mu_i_cache.MultisetSort();
      mu_fwd.MultisetSort();
      mu_req.MultisetSort();
      mu_resp.MultisetSort();
      if (p.compare(workingstate)) {
        StateCopy(workingstate,&temp); return TRUE; }
      StateCopy(workingstate,&temp);
      return FALSE;
    }
  return (p.compare(ns));
}

/********************
 Canonicalization by fast exhaustive generation of
 all permutations
 ********************/
void SymmetryClass::Exhaustive_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;
  Perm.ResetToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_cl_mut.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_cl_mut.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_i_directory.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_i_directory.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_cnt_fwd.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_cnt_fwd.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_i_cache.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_i_cache.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_fwd.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_fwd.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_req.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_req.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_resp.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_resp.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 ********************/
void SymmetryClass::Heuristic_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

  mu_i_directory.SimpleCanonicalize(Perm);

  mu_cnt_fwd.Canonicalize(Perm);

  mu_i_cache.Canonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_fwd.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_fwd.Limit(Perm);
  }

  Perm.SimpleToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_fwd.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_fwd.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_req.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_req.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_resp.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_resp.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 and use less local memory
 ********************/
void SymmetryClass::Heuristic_Small_Mem_Canonicalize(state* s)
{
  unsigned long cycle;
  static state temp;

  Perm.ResetToSimple();

  mu_i_directory.SimpleCanonicalize(Perm);

  mu_cnt_fwd.Canonicalize(Perm);

  mu_i_cache.Canonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_fwd.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_fwd.Limit(Perm);
  }

  Perm.SimpleToOne();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  mu_fwd.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_fwd.MultisetSort();
  mu_req.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_req.MultisetSort();
  mu_resp.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_resp.MultisetSort();
  BestPermutedState = *workingstate;
  BestInitialized = TRUE;

  cycle=1;
  while (Perm.NextPermutation())
    {
      if (args->perm_limit.value != 0
          && cycle++ >= args->perm_limit.value) break;
      StateCopy(workingstate, &temp);
      mu_fwd.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_fwd.MultisetSort();
      mu_req.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_req.MultisetSort();
      mu_resp.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_resp.MultisetSort();
      switch (StateCmp(workingstate, &BestPermutedState)) {
      case -1:
        BestPermutedState = *workingstate;
        break;
      case 1:
        break;
      case 0:
        break;
      default:
        Error.Error("funny return value from StateCmp");
      }
    }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Normalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and for all other variables, pick any remaining permutation
 ********************/
void SymmetryClass::Heuristic_Fast_Normalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

  mu_i_directory.SimpleCanonicalize(Perm);

  mu_cnt_fwd.Canonicalize(Perm);

  mu_i_cache.Canonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_fwd.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_fwd.Limit(Perm);
  }

  Perm.SimpleToOne();

  mu_fwd.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_fwd.MultisetSort();

  mu_req.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_req.MultisetSort();

  mu_resp.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_resp.MultisetSort();

};

/********************
  Include
 ********************/
#include "mu_epilog.hpp"

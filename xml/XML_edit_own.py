from lxml import etree

def patch_xml(source,target):

  parser = etree.XMLParser(remove_blank_text=True)

  tree = etree.parse(source,parser = parser)
  root = tree.getroot()
  my_namespaces = root.nsmap


  scalars=tree.findall('//ScalarVariable', my_namespaces)

  # Remove double variables
  doubles = 0
  checked = set()
  for scalar in scalars:
    if scalar.attrib['name'] in checked:
      scalar.getparent().remove(scalar)
      doubles +=1
    else:
      checked.add(scalar.attrib['name'])

  """
  alias = 0
  causality = 0
  for scalar in scalars:
        if scalar.attrib["causality"] == "parameter" or scalar.attrib["causality"] == "calculatedParameter":
          scalar.attrib["causality"] = "internal"
      causality+=1

    if scalar.attrib["causality"]=="output":
          scalar.attrib["causality"] = "internal"
      causality+=1

    if scalar.attrib["alias"] != "noAlias":
          scalar.attrib["alias"] = "noAlias"
      scalar.getparent().remove(scalar)
      alias +=1

  #Replace $START with ._0 and add ScalarVariable and BindingEquation for every change
  list=tree.findall('//exp:QualifiedNamePart',my_namespaces)
  ModelVariables = tree.findall('ModelVariables', my_namespaces)
  BindingEquations = tree.findall('equ:BindingEquations', my_namespaces)
  Dynamic = tree.findall('equ:DynamicEquations', my_namespaces)
  Equation = tree.findall('equ:Equation', my_namespaces)

  for e in list:
    if e.get('name') == '$START':
      equ = e.getparent().getparent().getparent()
      equ.getparent().remove(equ)

  # for e in list:
    # if e.get('name') == '$START':
    #   #remove $START and add _0
    #   name = list[list.index(e)+1].attrib['name']+'_0'
    #   list[list.index(e)+1].attrib['name'] = name
    #   e.getparent().remove(e)
    #   print("$START removed and replaced by", name)
    #
    #   #create ScalarVariable
    #   ScalarVariable = etree.SubElement(ModelVariables[0], 'ScalarVariable')
    #   ScalarVariable.attrib['name'] = name
    #   ScalarVariable.attrib['valueReference'] = '1'
    #   ScalarVariable.attrib['variability'] = 'parameter'
    #   ScalarVariable.attrib['causality'] = 'internal'
    #   ScalarVariable.attrib['alias'] = 'noAlias'
    #   etree.SubElement(ScalarVariable, 'Real').attrib['start'] = '0.5'
    #   QualifiedName = etree.SubElement(ScalarVariable, 'QualifiedName')
    #   etree.SubElement(QualifiedName, 'QualifiedNamePart').attrib['name'] = name
    #   etree.SubElement(ScalarVariable, 'isLinear').text = 'true'
    #   etree.SubElement(ScalarVariable, 'VariableCategory').text = 'independentParameter'
    #   print("ScalarVariable created")
    #
    #   #create BindingEquation
    #   BindingEquation = etree.SubElement(BindingEquations[0], "{%s}BindingEquation" % (my_namespaces["equ"]))
    #   Parameter = etree.SubElement(BindingEquation, '{%s}Parameter' % (my_namespaces["equ"]))
    #   etree.SubElement(Parameter, '{%s}QualifiedNamePart' % (my_namespaces["exp"])).attrib['name'] = name
    #   BindingExp = etree.SubElement(BindingEquation, '{%s}BindingExp' % (my_namespaces["equ"]))
    #   etree.SubElement(BindingExp, '{%s}IntegerLiteral' % (my_namespaces["exp"])).text = '0.5'
    #   print("BindingEquation created")

  #Recursively go through all equations and look if their children are all empty, if so ==> remove
  def recursively_empty(e):
    if e.text:
       if not len(e.text.strip())==0:
         return False
    if bool(e.attrib):
      return False
    return all((recursively_empty(c) for c in e.iterchildren()))

  equations=tree.findall('//equ:Equation',my_namespaces)


  # Elvate nested QualifiedNamePart
  for elem in tree.findall("//exp:QualifiedNamePart/exp:QualifiedNamePart", my_namespaces):
    ind = elem.getparent().getparent()
    elem.getparent().remove(elem)
    ind.append(elem)

  empty = 0
  for elem in equations:
      parent = elem.getparent()
      if recursively_empty(elem):
          parent.remove(elem)
          empty +=1

  if 'SimpleBuildings.' in source:
    DynamicEquation = etree.SubElement(Dynamic[0], "{%s}Equation" % (my_namespaces["equ"]))
    Sub = etree.SubElement(DynamicEquation, '{%s}Sub' % (my_namespaces["exp"]))
    Identifier = etree.SubElement(Sub, '{%s}Identifier' % (my_namespaces["exp"]))
    etree.SubElement(Identifier, '{%s}QualifiedNamePart' % (my_namespaces["exp"])).attrib['name'] = "senTZon"
    etree.SubElement(Identifier, '{%s}QualifiedNamePart' % (my_namespaces["exp"])).attrib['name'] = "port"
    etree.SubElement(Identifier, '{%s}QualifiedNamePart' % (my_namespaces["exp"])).attrib['name'] = "Q_flow"
    etree.SubElement(Sub, '{%s}RealLiteral' % (my_namespaces["exp"])).text = "0.0"


  print("Double variables removed:", doubles)
  print("Causality attributes changed:", causality)
  print("Aliases removed:", alias)
  print("Empty equations removed:", empty)
  tree.write(target, pretty_print=True)
"""

def inspect_xml(source):

  parser = etree.XMLParser(remove_blank_text=True)

  tree = etree.parse(source,parser = parser)
  root = tree.getroot()
  my_namespaces = root.nsmap

  """

  print("List of states")
  scalars=tree.findall("//ScalarVariable[VariableCategory='state']", my_namespaces)
  i = 0
  for e in scalars:
    print("diffstate {i}. {name}".format(i=i,name=e.attrib['name']))
    i=i+1
  scalars=tree.findall("//ScalarVariable[@causality='internal'][VariableCategory='algebraic']", my_namespaces)
  for e in scalars:
    print("algstate  {i}. {name}".format(i=i,name=e.attrib['name']))
    i=i+1

  scalars=tree.findall("//ScalarVariable[@causality='output']", my_namespaces)
  for e in scalars:
    print("outputs  {i}. {name}".format(i=i,name=e.attrib['name']))
    i=i+1
  
  scalars=tree.findall("//ScalarVariable[@causality='input']", my_namespaces)
  for e in scalars:
    print("inputs  {i}. {name}".format(i=i,name=e.attrib['name']))
    i=i+1

  """

  print("List of functions")
  i = 0
  functions=tree.findall("//fun:Function", my_namespaces)
  fs = []
  keep = {}
  for f in functions:
    
    # First, get name:
    fname = get_name(f[0], my_namespaces)   
    
    # get input vars
    num_outs = 0
    outs = []
    for output_var in f[1:]:
        if output_var.tag.endswith("OutputVariable"):
              # what is the name
          name = construct_expr(output_var, my_namespaces, keep)
          import casadi
          var = casadi.MX.sym(name)
          outs.append(var)
          
          num_outs += 1
          keep[name] = var
        else:
          break # we are at input vars
     
     
    num_ins = 0
    ins = []   
    for input_var in f[(1+num_outs):]:
        if input_var.tag.endswith("InputVariable"):
          # what is the name
          name = construct_expr(input_var, my_namespaces, keep)
          import casadi
          var = casadi.MX.sym(name)
          ins.append(var)
          keep[name] = var
          num_ins += 1
          
        else:
          break # we are at input vars
    
       
        
    #print("equation  {i}. {str}".format(i=i,str=construct_expr(f[0],my_namespaces, keep)))
    
    """
    New logic for parsing functions:
      Name, inputs, outputs are flat.
      Algorithm, i.e. the function body, is nested.
    """
    
    # call construct expr on algorithm section:
    _f = construct_expr(f[1+num_outs+num_ins], my_namespaces, keep)
    F = casadi.Function(fname, ins, [_f])    
    print("function  {i}. {str}".format(i=i,str=F))
    i=i+1
    
    #fs.append(F)
    keep[fname] = F


  
def get_functions_xml(source):
    
  parser = etree.XMLParser(remove_blank_text=True)

  tree = etree.parse(source,parser = parser)
  root = tree.getroot()
  my_namespaces = root.nsmap


  print("List of functions")
  i = 0
  functions=tree.findall("//fun:Function", my_namespaces)
  fs = []
  keep = {}
  for f in functions:
    
    # First, get name:
    fname = get_name(f[0], my_namespaces)   
    
    # get input vars
    num_outs = 0
    outs = []
    for output_var in f[1:]:
        if output_var.tag.endswith("OutputVariable"):
              # what is the name
          name = construct_expr(output_var, my_namespaces, keep)
          import casadi
          var = casadi.MX.sym(name)
          outs.append(var)
          
          num_outs += 1
          keep[name] = var
        else:
          break # we are at input vars
     
     
    num_ins = 0
    ins = []   
    for input_var in f[(1+num_outs):]:
        if input_var.tag.endswith("InputVariable"):
          # what is the name
          name = construct_expr(input_var, my_namespaces, keep)
          import casadi
          var = casadi.MX.sym(name)
          ins.append(var)
          keep[name] = var
          num_ins += 1
          
        else:
          break # we are at input vars
    
       
        
    #print("equation  {i}. {str}".format(i=i,str=construct_expr(f[0],my_namespaces, keep)))
    
    """
    New logic for parsing functions:
      Name, inputs, outputs are flat.
      Algorithm, i.e. the function body, is nested.
    """
    
    # call construct expr on algorithm section:
    _f = construct_expr(f[1+num_outs+num_ins], my_namespaces, keep)
    F = casadi.Function(fname, ins, [_f], [list(map(lambda x: x.name(), ins))], ["y"])    
    print("function  {i}. {str}".format(i=i,str=F))
    i=i+1
    
    #fs.append(F)
    keep[fname] = F
    
    return keep



  """
  print("List of equations")
  i = 0
  equations=tree.findall("//equ:DynamicEquations/equ:Equation", my_namespaces)
  eqs = []
  for e in equations:
        #print("equation  {i}. {str}".format(i=i,str=repr_expr(e[0],my_namespaces)))
    #print("equation  {i}. {str}".format(i=i,str=repr_expr(e[0],my_namespaces)))
    _e = construct_expr(e[0], my_namespaces, keep)
    #F = casadi.Function(fname, ins, [_f])    
    eqs.append(_e)
    print("equation  {i}. {str}".format(i=i,str=_e))
    
    i=i+1
    
  print(keep)
  """
  
def get_name(node, my_namespaces):
  """
  First node: name
  """
  if node.tag.endswith("Name"):
          # function input or output
  #return repr_expr(e[0],my_namespaces)
    nameparts = []
    for np in node.findall(".//exp:QualifiedNamePart", my_namespaces):
      nameparts.append(np.attrib["name"])
    return "_".join(nameparts)
  else:
    raise Exception
  
  
"""
def get_args(node, my_namespaces):
  assert node.endswith("Arguments")
          # function input or output
  #return repr_expr(e[0],my_namespaces)
  names = []
  nameparts = []
  
  arg = node[0]
  
  while arg.tag.endswith("")
  for np in node.findall(".//exp:QualifiedNamePart", my_namespaces):
    nameparts.append(np.attrib["name"])
  return "_".join(nameparts)
"""
    
    

# need to construct functions for possible calls in repr_expr


def repr_expr(e,my_namespaces):
  if e.tag.endswith("Sub"):
    return repr_expr(e[0],my_namespaces)-repr_expr(e[1],my_namespaces)
  #elif "Identifier" in e.tag:
  elif e.tag.endswith("Identifier"):
    nameparts = []
    for np in e.findall(".//exp:QualifiedNamePart", my_namespaces):
      nameparts.append(np.attrib['name'])
    import casadi
    return casadi.MX.sym(".".join(nameparts))
  #elif "Mul" in e.tag:
  elif e.tag.endswith("Mul"):
    return repr_expr(e[0],my_namespaces)*repr_expr(e[1],my_namespaces)
  #elif "Div" in e.tag:
  elif e.tag.endswith("Div"):
    return repr_expr(e[0],my_namespaces)/repr_expr(e[1],my_namespaces)
  #elif "Add" in e.tag:
  elif e.tag.endswith("Add"):
    return repr_expr(e[0],my_namespaces)+repr_expr(e[1],my_namespaces)
  #elif "Neg" in e.tag:
  elif e.tag.endswith("Neg"):
    return -repr_expr(e[0],my_namespaces)
  #elif "Abs" in e.tag:
  elif e.tag.endswith("Abs"):
    import casadi
    return (casadi.fabs(repr_expr(e[0],my_namespaces)))
  #elif "RealLiteral" in e.tag:
  elif e.tag.endswith("RealLiteral"):
    return float(e.text)
  ####################### FUNCTION #############################
  elif e.tag.endswith("OutputVariable") or e.tag.endswith("InputVariable"):
        #return float(e.text)
    nameparts = []
    for np in e.findall(".//exp:QualifiedNamePart", my_namespaces):
      nameparts.append(np.attrib['name'])
      #assert len(nameparts) == 1
      #import casadi
      #return casadi.MX.sym(nameparts[0])
      return nameparts[0]
  elif e.tag.endswith("Real"):
        #return float(e.text)
    return repr_expr(e[0],my_namespaces)
  elif e.tag.endswith("Name"):
        # function input or output
    #return repr_expr(e[0],my_namespaces)
    nameparts = []
    for np in e.findall(".//exp:QualifiedNamePart", my_namespaces):
      nameparts.append(np.attrib['name'])
    import casadi
    #return casadi.MX.sym(".".join(nameparts))
    return ".".join(nameparts) + ": " + repr_expr(e[1], my_namespaces)
  #elif e.tag.endswith("QualifiedNamePart"):
    # function input or output
  #elif "Pow" in e.tag:
  elif e.tag.endswith("Pow"):
    return repr_expr(e[0], my_namespaces)**(repr_expr(e[1], my_namespaces))
  elif e.tag.endswith("Exp"):
    import casadi
    return casadi.exp(repr_expr(e[0], my_namespaces))
  elif e.tag.endswith("FunctionCall"):
    # need the function firs
    
    # what is the name of the function?
    fname = get_name(e[0], my_namespaces)
    
    
    import casadi
    return casadi.exp(repr_expr(e[0], my_namespaces))
      
    #return repr_expr(casadi.exp(e[0]), my_namespaces)
    #return casadi.exp(repr_expr(e, my_namespaces))
  elif "Der" in e.tag:
    import casadi
    return casadi.MX.sym("der_"+repr_expr(e[0],my_namespaces).name())
  else:
    raise Exception(e)

def construct_expr(e, my_namespaces, keep):
      
  ####################### FUNCTION #############################
  if e.tag.endswith("OutputVariable") or e.tag.endswith("InputVariable"):
        #return float(e.text)
    nameparts = []
    for np in e.findall(".//exp:QualifiedNamePart", my_namespaces):
      nameparts.append(np.attrib['name'])
      #assert len(nameparts) == 1
      #import casadi
      #return casadi.MX.sym(nameparts[0])
      return nameparts[0]
  elif e.tag.endswith("Real"):
        #return float(e.text)
    return repr_expr(e[0],my_namespaces)
  elif e.tag.endswith("Name"):
        # function input or output
    #return repr_expr(e[0],my_namespaces)
    nameparts = []
    for np in e.findall(".//exp:QualifiedNamePart", my_namespaces):
      nameparts.append(np.attrib['name'])
    import casadi
    #return casadi.MX.sym(".".join(nameparts))
    return ".".join(nameparts) + ": " + repr_expr(e[1], my_namespaces)
  #elif e.tag.endswith("QualifiedNamePart"):
    # function input or output
  #elif "Pow" in e.tag:
  elif e.tag.endswith("Algorithm"):
    return construct_expr(e[0], my_namespaces, keep)
  
  elif e.tag.endswith("Assign"):
    """
    assert that lhs's matches output?
    otherwise, output variables are not part of expressions. 
    """
    
    # TODO: implement check against 'keep'
    
    return construct_expr(e[0], my_namespaces, keep) = construct_expr(e[1], my_namespaces, keep)
  
  elif e.tag.endswith("Expression"):
    
    return construct_expr(e[0], my_namespaces, keep)
  
  elif e.tag.endswith("Smooth"):
    import casadi
    # how to implement tanh-switching?
    # See https://www.j-raedler.de/2010/10/smooth-transition-between-functions-with-tanh/
    return casadi.tanh(construct_expr(e[0], my_namespaces, keep))
  
  elif e.tag.endswith("If"):
    import casadi
    # if_else: <cond>, <then>, <else>
    return casadi.if_else(construct_expr(e[0], my_namespaces, keep), \
                          construct_expr(e[1], my_namespaces, keep), \
                          construct_expr(e[2], my_namespaces, keep))
  
  elif e.tag.endswith("Condition"):
    import casadi
    return construct_expr(e[0], my_namespaces, keep)
  
  elif e.tag.endswith("Statements"):
    import casadi
    return construct_expr(e[0], my_namespaces, keep)

  elif e.tag.endswith("Else"):
    import casadi
    return construct_expr(e[0], my_namespaces, keep)
  
  elif e.tag.endswith("LogGt"):
    import casadi
    return construct_expr(e[0], my_namespaces, keep) > construct_expr(e[1], my_namespaces, keep)
  
  elif e.tag.endswith("LogLt"):
    import casadi
    return construct_expr(e[0], my_namespaces, keep) < construct_expr(e[1], my_namespaces, keep)
    
  elif e.tag.endswith("Mul"):
    import casadi
    return construct_expr(e[0], my_namespaces, keep)*construct_expr(e[1], my_namespaces, keep)
  #elif "Div" in e.tag:
  elif e.tag.endswith("Div"):
    import casadi
    return construct_expr(e[0], my_namespaces, keep)/construct_expr(e[1], my_namespaces, keep)
  #elif "Add" in e.tag:
  elif e.tag.endswith("Add"):
    import casadi
    return construct_expr(e[0], my_namespaces, keep) + construct_expr(e[1], my_namespaces, keep)
  
  elif e.tag.endswith("Sub"):
    import casadi
    return construct_expr(e[0], my_namespaces, keep) - construct_expr(e[1], my_namespaces, keep)
  
  #elif "Neg" in e.tag:
  elif e.tag.endswith("Neg"):
    import casadi
    return -construct_expr(e[0], my_namespaces, keep)
  #elif "Abs" in e.tag:
  elif e.tag.endswith("Abs"):
    import casadi
    return (casadi.fabs(construct_expr(e[0], my_namespaces, keep)))
  #elif "RealLiteral" in e.tag:
  elif e.tag.endswith("RealLiteral"):
    import casadi
    return float(e.text)
  
  elif e.tag.endswith("Identifier"): # fetch the variable:
    import casadi
    nameparts = []
    for np in e.findall(".//exp:QualifiedNamePart", my_namespaces):
      nameparts.append(np.attrib['name'])
    #assert len(nameparts) == 1
    # if variable in keep, return it. 
    # otherwise, create
    name = ".".join(nameparts)
    """
    if nameparts[0] in keep:
      return keep[nameparts[0]]
    else:
      var = casadi.MX.sym(".".join(nameparts[0]))
    """
    if name in keep:
      return keep[name]
    else:
      var = casadi.MX.sym(name)
      keep[name] = var
      return var
  
  
  
  elif e.tag.endswith("Pow"):
    return repr_expr(e[0], my_namespaces)**(repr_expr(e[1], my_namespaces))
  elif e.tag.endswith("Exp"):
    import casadi
    return casadi.exp(repr_expr(e[0], my_namespaces))
  elif e.tag.endswith("FunctionCall"):
    # need the function firs
    fname = get_name(e[0], my_namespaces)
    func = keep[fname]
    import casadi
    
    # collect args
    args = []
    for _arg in e[1]:
      arg = construct_expr(_arg, my_namespaces, keep)
      args.append(arg)
    # 
    return func(*args)
    
    
    #return casadi.exp(repr_expr(e[0], my_namespaces))
      
    #return repr_expr(casadi.exp(e[0]), my_namespaces)
    #return casadi.exp(repr_expr(e, my_namespaces))
  elif "Der" in e.tag:
    import casadi
    return casadi.MX.sym("der_"+repr_expr(e[0],my_namespaces).name())
  else:
    raise Exception(e)
  
  """
  def read_expr(node):

    
    fullname = node.name
    
    if (name=="Add"): 
      return read_expr(node[0]) + read_expr(node[1])
    elif (name=="Acos"):
      return acos(read_expr(node[0]))
    elif (name=="Asin"):
      return asin(read_expr(node[0]))
    elsif (name=="Atan") {
      return atan(read_expr(node[0]));
    } else if (name=="Cos") {
      return cos(read_expr(node[0]));
    } else if (name=="Der") {
      return variable(read_variable(node[0]).der_of).v;
    } else if (name=="Div") {
      return read_expr(node[0]) / read_expr(node[1]);
    } else if (name=="Exp") {
      return exp(read_expr(node[0]));
    } else if (name=="Identifier") {
      return read_variable(node).v;
    } else if (name=="IntegerLiteral" || name=="BooleanLiteral") {
      casadi_int val;
      node.get(&val);
      return val;
    } else if (name=="Instant") {
      double val;
      node.get(&val);
      return val;
    } else if (name=="Log") {
      return log(read_expr(node[0]));
    } else if (name=="LogLeq") { // Logical less than equal
      return read_expr(node[0]) <= read_expr(node[1]);
    } else if (name=="LogGeq") { // Logical greater than equal
      return read_expr(node[0]) >= read_expr(node[1]);
    } else if (name=="LogLt") { // Logical less than
      return read_expr(node[0]) < read_expr(node[1]);
    } else if (name=="LogGt") { // Logical greater than
      return read_expr(node[0]) > read_expr(node[1]);
    } else if (name=="Max") {
      return fmax(read_expr(node[0]), read_expr(node[1]));
    } else if (name=="Min") {
      return fmin(read_expr(node[0]), read_expr(node[1]));
    } else if (name=="Mul") { // Multiplication
      return read_expr(node[0]) * read_expr(node[1]);
    } else if (name=="Neg") {
      return -read_expr(node[0]);
    } else if (name=="NoEvent") {
      // NOTE: This is a workaround, we assume that whenever NoEvent occurs,
      // what is meant is a switch
      casadi_int n = node.size();

      // Default-expression
      MX ex = read_expr(node[n-1]);

      // Evaluate ifs
      for (casadi_int i=n-3; i>=0; i -= 2) {
        ex = if_else(read_expr(node[i]), read_expr(node[i+1]), ex);
      }

      return ex;
    } else if (name=="Pow") {
      return pow(read_expr(node[0]), read_expr(node[1]));
    } else if (name=="RealLiteral") {
      double val;
      node.get(&val);
      return val;
    } else if (name=="Sin") {
      return sin(read_expr(node[0]));
    } else if (name=="Sqrt") {
      return sqrt(read_expr(node[0]));
    } else if (name=="StringLiteral") {
      casadi_error(node.text);
    } else if (name=="Sub") {
      return read_expr(node[0]) - read_expr(node[1]);
    } else if (name=="Tan") {
      return tan(read_expr(node[0]));
    } else if (name=="Time") {
      return var(t_.at(0));
    } else if (name=="TimedVariable") {
      return read_variable(node[0]).v;
    } else if (name=="FunctionCall") {
      // Get the name of the function
      std::string fname = qualified_name(node["exp:Name"]);
      casadi_warning("Function call to '" + fname + "' incomplete");
      // Collect the arguments
      const XmlNode& args = node["exp:Arguments"];
      std::vector<MX> farg(args.size());
      for (casadi_int i = 0; i < args.size(); ++i) {
        // Lift input arguments
        Variable& v = new_variable("w_" + str(w_.size()));
        v.v = MX::sym(v.name);
        // Add to list of variables
        w_.push_back(v.index);
        // Set binding expression
        v.beq = read_expr(args[i]);
        // Add to list of function arguments
        farg[i] = v.v;
      }
      // Return argument (scalar for now)
      Variable& r = new_variable("w_" + str(w_.size()));
      r.v = MX::sym(r.name);
      // Add to list of variables
      w_.push_back(r.index);
      // Return output variable
      return r.v;
    } else if (name=="Array") {
      // Array of arguments
      std::vector<MX> v(node.size());
      for (casadi_int i = 0; i < v.size(); ++i) v[i] = read_expr(node[i]);
      return vertcat(v);
    }

    // throw error if reached this point
    casadi_error("Unknown node: " + name);
  } catch (std::exception& e) {
    THROW_ERROR_NODE("read_expr", node, e.what());
    return {};
  }
}
"""
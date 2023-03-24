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


def inspect_xml(source):

  parser = etree.XMLParser(remove_blank_text=True)

  tree = etree.parse(source,parser = parser)
  root = tree.getroot()
  my_namespaces = root.nsmap

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

  print("List of equations")
  i = 0
  equations=tree.findall("//equ:DynamicEquations/equ:Equation", my_namespaces)
  for e in equations:
    print("equation  {i}. {str}".format(i=i,str=repr_expr(e[0],my_namespaces)))
    i=i+1

def repr_expr(e,my_namespaces):
  if e.tag.endswith("Sub"):
    return repr_expr(e[0],my_namespaces)-repr_expr(e[1],my_namespaces)
  elif "Identifier" in e.tag:
    nameparts = []
    for np in e.findall(".//exp:QualifiedNamePart", my_namespaces):
      nameparts.append(np.attrib['name'])
    import casadi
    return casadi.MX.sym(".".join(nameparts))
  elif "Mul" in e.tag:
    return repr_expr(e[0],my_namespaces)*repr_expr(e[1],my_namespaces)
  elif "Div" in e.tag:
    return repr_expr(e[0],my_namespaces)/repr_expr(e[1],my_namespaces)
  elif "Add" in e.tag:
    return repr_expr(e[0],my_namespaces)+repr_expr(e[1],my_namespaces)
  elif "Neg" in e.tag:
    return -repr_expr(e[0],my_namespaces)
  elif "RealLiteral" in e.tag:
    return float(e.text)
  elif "Pow" in e.tag:
    return repr_expr(e[0], my_namespaces)**(repr_expr(e[1], my_namespaces))
  elif "Exp" in e.tag:
    import casadi
    return casadi.exp(repr_expr(e[0], my_namespaces))
  elif "Der" in e.tag:
    import casadi
    return casadi.MX.sym("der_"+repr_expr(e[0],my_namespaces).name())
  else:
    raise Exception(e)

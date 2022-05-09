#ifndef jetsubstructuremomenttools_ktmassdroptool_header
#define jetsubstructuremomenttools_ktmassdroptool_header

#include "JetSubStructureMomentTools/JetSubStructureMomentToolsBase.h"

class KtMassDropTool :
  public JetSubStructureMomentToolsBase {
    ASG_TOOL_CLASS(KtMassDropTool, IJetModifier)
    
    public:
      // Constructor and destructor
      KtMassDropTool(std::string name);

      int modifyJet(xAOD::Jet &jet) const;
};


#endif

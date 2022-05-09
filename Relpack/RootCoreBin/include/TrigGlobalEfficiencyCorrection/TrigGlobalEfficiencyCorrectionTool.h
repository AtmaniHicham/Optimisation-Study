// contact: jmaurer@cern.ch

#ifndef TOOLPROTOTYPES_TRIGGLOBALEFFICIENCYCORRECTIONTOOL_H
#define TOOLPROTOTYPES_TRIGGLOBALEFFICIENCYCORRECTIONTOOL_H 1

#include "TriggerAnalysisInterfaces/ITrigGlobalEfficiencyCorrectionTool.h"

#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandleArray.h"
#include "ElectronEfficiencyCorrection/IAsgElectronEfficiencyCorrectionTool.h"
#include "MuonEfficiencyCorrections/IMuonTriggerScaleFactors.h"

#include <string>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <functional>
#include <boost/container/container_fwd.hpp>

class TrigGlobalEfficiencyCorrectionTool: public asg::AsgTool, public virtual ITrigGlobalEfficiencyCorrectionTool
{
public: 
	ASG_TOOL_CLASS(TrigGlobalEfficiencyCorrectionTool,ITrigGlobalEfficiencyCorrectionTool)

	TrigGlobalEfficiencyCorrectionTool(const std::string& name);
	virtual ~TrigGlobalEfficiencyCorrectionTool();

	virtual StatusCode  initialize() override;

	virtual CP::CorrectionCode getEfficiencyScaleFactor(const std::vector<const xAOD::Electron*>& electrons, const std::vector<const xAOD::Muon*>& muons, double& efficiencyScaleFactor) override;
	virtual CP::CorrectionCode getEfficiencyScaleFactor(unsigned runNumber, const std::vector<const xAOD::Electron*>& electrons, const std::vector<const xAOD::Muon*>& muons, double& efficiencyScaleFactor) override;
	virtual CP::CorrectionCode getEfficiency(const std::vector<const xAOD::Electron*>& electrons, const std::vector<const xAOD::Muon*>& muons, double& efficiencyData, double& efficiencyMc) override;
	virtual CP::CorrectionCode getEfficiency(unsigned runNumber, const std::vector<const xAOD::Electron*>& electrons, const std::vector<const xAOD::Muon*>& muons, double& efficiencyData, double& efficiencyMc) override;
	
	virtual CP::CorrectionCode getEfficiencyScaleFactor(const std::vector<const xAOD::IParticle*>& particles, double& efficiencyScaleFactor) override;
	virtual CP::CorrectionCode getEfficiencyScaleFactor(unsigned runNumber, const std::vector<const xAOD::IParticle*>& particles, double& efficiencyScaleFactor) override;
	virtual CP::CorrectionCode getEfficiency(const std::vector<const xAOD::IParticle*>& particles, double& efficiencyData, double& efficiencyMc) override;
	virtual CP::CorrectionCode getEfficiency(unsigned runNumber, const std::vector<const xAOD::IParticle*>& particles, double& efficiencyData, double& efficiencyMc) override;	
	
	class Efficiencies; // public since used with a STL container
	struct CachedEfficiencies; // public since used with a STL container
	class LeptonDetails; // public since used with a STL container
	
private: 
	class Leptons;
	
	// Properties:
	ToolHandleArray<IAsgElectronEfficiencyCorrectionTool> m_suppliedElectronEfficiencyTools;
	ToolHandleArray<IAsgElectronEfficiencyCorrectionTool> m_suppliedElectronScaleFactorTools;
	ToolHandleArray<CP::IMuonTriggerScaleFactors> m_suppliedMuonTools;
	std::map<std::string, std::string> m_legsPerTool;
	std::map<std::string, std::string> m_triggerCb;
	std::string m_triggerCb15;
	std::string m_triggerCb16;
	bool m_guessHierarchy = false;
	std::string m_leptonTagDecorations;
	std::map<std::string, std::string> m_tagsPerTool;
	std::map<std::string, std::string> m_electronLegsPerTag;
	std::map<std::string, std::string> m_muonLegsPerTag;
	unsigned long m_numberOfToys;

	// Internal stuff:
	std::hash<std::string> m_hasher; //!
	
	// these containers are always empty except transiently during the initialization
	std::vector<std::tuple<std::string,float,float> > m_declaredHierarchies; //!
	std::map<size_t, std::tuple<int,size_t,size_t,size_t> > m_declaredTriggers; //!
	std::map<std::string, std::pair<int,int> > m_declaredPeriods; //!

	// these containers are not modified very often, change them to flat_map/flat_set/flat_multimap if they get supported flawlessly!
	std::map<size_t,float > m_declaredThresholds; //!
	std::multimap<size_t,std::tuple<float,float,unsigned long> > m_cachedLegRankings; //!
	std::map<size_t, ToolHandle<IAsgElectronEfficiencyCorrectionTool>* > m_electronSfTools; //!
	std::map<size_t, ToolHandle<IAsgElectronEfficiencyCorrectionTool>* > m_electronEffTools; //!
	std::map<size_t, ToolHandle<CP::IMuonTriggerScaleFactors>* > m_muonTools; //!
	std::set<size_t> m_validLegTagPairs; //! // only filled for muons
	std::map<size_t, std::string> m_muonTriggerNames; //!
	std::map<size_t, std::string> m_dictionary; //!
	
	struct Hierarchy;
	Hierarchy* m_hierarchies = nullptr; //!
	size_t* m_hierarchyData = nullptr; //!
	short m_nHierarchies = 0; //!
	
	CachedEfficiencies* m_cachedEfficiencies = nullptr; //!
	unsigned short m_cachedEfficienciesSize = 0; //!
	unsigned short m_cachedEfficienciesCapacity = 0; //!

	bool m_usingTags = false; //!
	
	bool m_initialized = false; //!
	CP::CorrectionCode m_cpCode = CP::CorrectionCode::Ok; //!
	
	std::vector<std::tuple<SG::AuxElement::Decorator<char>,size_t,bool> > m_leptonTagDecorators; //!
	SG::AuxElement::Decorator<unsigned int> m_runNumberDecorator; //!
	
	std::map<std::pair<unsigned,unsigned>, std::function<bool(const Leptons&,unsigned,Efficiencies&)> > m_globalEfficiencyFunctions; //!
	
	// Internal methods:
	template<typename Key> using flat_set = boost::container::flat_set<Key>;
	void declareHierarchies();
	void declareTriggers();
	void declareThresholds();
	void declarePeriods();
	bool loadHierarchies();
	bool enumerateTools(bool& useDefaultTools);
	bool loadTriggerCombination(bool useDefaultTools);
	bool loadTagsConfiguration();
	bool getPeriodBoundaries(const std::string& period, std::pair<unsigned,unsigned>& boundaries);
	bool retrieveRunNumber(unsigned& runNumber);
	bool aboveThreshold(const LeptonDetails& p,size_t leg) const;
	bool chooseLegs(float pt, const std::map<size_t,bool>& legs, size_t& tightestMatchedLeg, size_t& loosestUnmatchedLeg);
	unsigned long getCachedTriggerLegsRanking(float pt, const flat_set<size_t>& legs);
	size_t getLoosestLegAboveThreshold(const LeptonDetails& lepton, const flat_set<size_t>& legs, bool& success);
	int getLoosestLegIndex(const LeptonDetails& lepton, const flat_set<size_t>& legs, bool& success);
	size_t getLoosestLeg(const LeptonDetails& lepton, const flat_set<size_t>& legs, bool& success);
	std::pair<size_t,size_t> getTwoLoosestLegs(const LeptonDetails& lepton, const flat_set<size_t>& legs, bool& success);
	bool rankTriggerLegs(float pt, const flat_set<size_t>& legs, unsigned long& ranking, float&ptmin, float&ptmax);
	std::vector<std::pair<size_t,unsigned>> sortLegs(float pt,const std::map<size_t,bool>& legs,float&ptmin,float&ptmax);
	template<class Particle> bool updateLeptonsContainer(Leptons& leptons, const std::vector<const Particle*>& particles);
	void updateMuonTriggerNames(size_t leg, const std::string& name);
	bool getTriggerLegEfficiencies(const xAOD::Electron* p, size_t leg, size_t tag, Efficiencies& efficiencies);
	bool getTriggerLegEfficiencies(const xAOD::Muon* p, unsigned runNumber, size_t leg, Efficiencies& efficiencies);
	Efficiencies getCachedTriggerLegEfficiencies(const LeptonDetails& p, unsigned runNumber, size_t leg, bool& success);
	CP::CorrectionCode getEfficiencyScaleFactor(unsigned runNumber, const Leptons& leptons, double& efficiencyScaleFactor);
	CP::CorrectionCode getEfficiency(unsigned runNumber, const Leptons& leptons, double& efficiencyData, double& efficiencyMc);	
	bool checkAndRecord(CP::CorrectionCode&& cc)
	{
	   cc.ignore();
	   if(cc>m_cpCode) m_cpCode = cc;
	   return cc==CP::CorrectionCode::Ok;
	}
	
	enum
	{
		TT_GENERIC_SINGLELEPTON = 0x100,
		TT_SINGLE_E, TT_SINGLE_MU,
		TT_GENERIC_DILEPTON = 0x200,
		TT_2E_SYM, TT_2E_ASYM, TT_EMU, TT_2MU_SYM, TT_2MU_ASYM,
		TT_GENERIC_TRILEPTON = 0x400,
		TT_3E_SYM, TT_3E_HALFSYM, TT_3E_ASYM, TT_2E_MU_SYM, TT_2E_MU_ASYM, 
		TT_2MU_E_SYM, TT_2MU_E_ASYM, TT_3MU_SYM, TT_3MU_HALFSYM, TT_3MU_ASYM
		// to add more generic types (4L?) use 0x800, 0x1000, 0x2000 base...
	};

	bool globalEfficiency_One1L(const Leptons&, unsigned, xAOD::Type::ObjectType type, size_t leg, Efficiencies&);
	bool globalEfficiency_One1EOne1Mu(const Leptons&, unsigned, size_t electronLeg, size_t muonLeg, Efficiencies&);
	bool globalEfficiency_Several1L(const Leptons&, unsigned, const flat_set<size_t>& electronLegs, const flat_set<size_t>& muonLegs, Efficiencies&);
	bool globalEfficiency_Several1L(const Leptons&, unsigned, xAOD::Type::ObjectType type, const flat_set<size_t>& legs, Efficiencies&);
	bool globalEfficiency_One2Lsym(const Leptons&, unsigned, xAOD::Type::ObjectType type, size_t leg, Efficiencies&);
	bool globalEfficiency_One2Lasym(const Leptons&, unsigned, xAOD::Type::ObjectType type, size_t leg1, size_t leg2, Efficiencies&);
	bool globalEfficiency_OneEMu(const Leptons&, unsigned, size_t electronLeg, size_t muonLeg, Efficiencies&);
	bool globalEfficiency_OneEMuSeveral1L(const Leptons&, unsigned, size_t dilepElectronLeg, size_t dilepMuonLeg, 
		const flat_set<size_t>& singleElectronLegs, const flat_set<size_t>& singleMuonLegs, Efficiencies&);
	bool globalEfficiency_One2LsymSeveral1L(const Leptons&, unsigned, xAOD::Type::ObjectType type, size_t leg2L, const flat_set<size_t>& legs1L, Efficiencies&);
	bool globalEfficiency_One2LasymSeveral1L(const Leptons&, unsigned, xAOD::Type::ObjectType type, size_t leg2L1, size_t leg2L2, const flat_set<size_t>& legs1L, Efficiencies&);
	bool globalEfficiency_Two2LsymSeveral1L(const Leptons&, unsigned, xAOD::Type::ObjectType type, size_t leg2Lsym1, size_t leg2Lsym2, const flat_set<size_t>& legs1L, Efficiencies&);
	bool globalEfficiency_One2LasymOne2LsymSeveral1L(const Leptons&, unsigned, xAOD::Type::ObjectType type, size_t leg2Lasym1, size_t leg2Lasym2, 
		size_t leg2Lsym, const flat_set<size_t>& legs1L, Efficiencies&);
	bool globalEfficiency_One3Lsym(const Leptons&, unsigned, xAOD::Type::ObjectType type, size_t leg, Efficiencies&);
	bool globalEfficiency_One3Lhalfsym(const Leptons&, unsigned, xAOD::Type::ObjectType type, size_t legAsym, size_t legSym, Efficiencies&);
	bool globalEfficiency_One2LOneEmu(const Leptons&, unsigned, xAOD::Type::ObjectType type, size_t dilepLeg1, size_t dilepLeg2,
		size_t emuElectronLeg, size_t emuMuonLeg, Efficiencies&);
	bool globalEfficiency_One2EOneEmuOne2Mu(const Leptons&, unsigned, size_t diELeg1, size_t diELeg2, size_t emuELeg, size_t emuMuLeg, 
		size_t diMuLeg1, size_t diMuLeg2, Efficiencies&);
	bool globalEfficiency_One2EOneEmuOne2MuSeveral1L(const Leptons&, unsigned, size_t diELeg1, size_t diELeg2, size_t emuELeg, size_t emuMuLeg, 
		size_t diMuLeg1, size_t diMuLeg2, const flat_set<size_t>& singleElectronLegs, const flat_set<size_t>& singleMuonLegs, Efficiencies&);
	bool globalEfficiency_Two2ETwoEmuTwo2MuSeveral1L(const Leptons&, unsigned, size_t diELegAsym1, size_t diELegAsym2, size_t diELegSym, 
		size_t emu1ELeg, size_t emu1MuLeg, size_t emu2ELeg, size_t emu2MuLeg, size_t diMuLegAsym1, size_t diMuLegAsym2, size_t diMuLegSym, 
		const flat_set<size_t>& singleElectronLegs, const flat_set<size_t>& singleMuonLegs, Efficiencies&);
	bool globalEfficiency_One3Lmixed(const Leptons& leptons, unsigned runNumber, 
		xAOD::Type::ObjectType dominantType, size_t leg1a, size_t leg1b, size_t leg2, Efficiencies& globalEfficiencies);
	bool globalEfficiency_Two3LmixedCompl(const Leptons&, unsigned, 
		size_t legE1a, size_t legE1b, size_t legE2, size_t legM1, size_t legM2a, size_t legM2b, Efficiencies&);
		
	bool globalEfficiency_Toys(const Leptons&, unsigned, const std::vector<std::tuple<int,size_t,size_t,size_t> >& triggers, Efficiencies&);	
}; 

#endif //> !TOOLPROTOTYPES_TRIGGLOBALEFFICIENCYCORRECTION_H

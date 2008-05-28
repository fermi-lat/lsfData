#ifndef LSFDATA_METAEVENT_H
#define LSFDATA_METAEVENT_H 1

#include <iostream>
//#include <map>

#include "lsfData/LsfTime.h"
#include "lsfData/LsfRunInfo.h"
#include "lsfData/LsfDatagramInfo.h"
#include "lsfData/LsfGemScalers.h"
#include "lsfData/LsfConfiguration.h"
#include "lsfData/LsfKeys.h"
#include "lsfData/LpaHandler.h"

/** @class MetaEvent
*
* $Header: /nfs/slac/g/glast/ground/cvs/lsfData/lsfData/LsfMetaEvent.h,v 1.5 2008/05/22 05:02:20 heather Exp $
*/

namespace lsfData {
  
  class MetaEvent {
    
  public:
    
    MetaEvent( const RunInfo& run, const DatagramInfo& datagram, 
	       const GemScalers& scalers,
	       const Time& time,
	       const Configuration& configuration,
	       const LsfKeys& keys)
      :m_run(run),m_datagram(datagram),
       m_scalers(scalers),
       m_time(time),
       m_config(configuration.clone()),
       m_type(configuration.type()),
       m_keys(keys.clone()),
       m_ktype(keys.type()),
       m_gamma(0), m_pass(0), m_mip(0), m_hip(0), m_dgn(0), m_lpaHandler(0) {
   
    }

    MetaEvent()
      :m_config(0),
       m_type(enums::Lsf::NoRunType),
       m_keys(0),
       m_ktype(enums::Lsf::NoKeysType),
       m_gamma(0), m_pass(0), m_mip(0), m_hip(0), m_dgn(0), m_lpaHandler(0) {
    }
    
    MetaEvent( const MetaEvent& other ) :
       m_run(other.run()),
       m_datagram(other.datagram()),
       m_scalers(other.scalers()),
       m_time(other.time()),
       m_config(0),
       m_type(enums::Lsf::NoRunType) {
      if ( other.configuration() != 0 ) {
	m_config = other.configuration()->clone();
	m_type = other.configuration()->type();
      }
      if ( other.keys() != 0 ) {
	m_keys  = other.keys()->clone();
	m_ktype = other.keys()->type();
      }
      if (other.gammaFilter()) m_gamma = new lsfData::GammaHandlerRsdV0(*(other.gammaFilter()));
      if (other.mipFilter()) m_mip = new lsfData::MipHandlerRsdV0(*(other.mipFilter()));
      if (other.hipFilter()) m_hip = new lsfData::HipHandlerRsdV0(*(other.hipFilter()));
      if (other.dgnFilter()) m_dgn = new lsfData::DgnHandlerRsdV0(*(other.dgnFilter()));
      if (other.passthruFilter()) m_pass = new lsfData::PassthruHandlerRsdV0(*(other.passthruFilter()));
      if (other.lpaHandler()) m_lpaHandler = new lsfData::LpaHandler(*(other.lpaHandler()));

    }
    
    virtual ~MetaEvent(){
      delete m_config;
      delete m_keys;

      if (m_gamma) {
          delete m_gamma;
          m_gamma = 0;
      }
      if (m_mip) {
          delete m_mip;
          m_mip = 0;
      }
      if (m_hip) {
          delete m_hip;
          m_hip = 0;
      }
      if (m_dgn) {
          delete m_dgn;
          m_dgn = 0;
      }
      if (m_pass) {
          delete m_pass;
          m_pass = 0;
      }
      if (m_lpaHandler) {
          delete m_lpaHandler;
          m_lpaHandler = 0;
      }

    }

    inline void clear() {
       if (m_config) {
            delete m_config;
            m_config = 0;
        }
       if (m_keys) {
	 delete m_keys;
	 m_keys = 0;
       }
        m_run.clear();
        m_datagram.clear();
        m_scalers.clear();
        m_time.clear();      
        m_type = enums::Lsf::NoRunType;
	m_ktype = enums::Lsf::NoKeysType;
      if (m_gamma) {
          delete m_gamma;
          m_gamma = 0;
      }
      if (m_mip) {
          delete m_mip;
          m_mip = 0;
      }
      if (m_hip) {
          delete m_hip;
          m_hip = 0;
      }
      if (m_dgn) {
          delete m_dgn;
          m_dgn = 0;
      }
      if (m_pass) {
          delete m_pass;
          m_pass = 0;
      }
      if (m_lpaHandler) {
          delete m_lpaHandler;
          m_lpaHandler = 0;
      }

    }

    /// Information about the run this event is from
    inline const RunInfo& run() const { return m_run; };

    /// Information about the datagram this event came in
    inline const DatagramInfo& datagram() const { return m_datagram; }

    /// The extended context records
    inline const GemScalers& scalers() const { return m_scalers; }

    /// Information about the time markers associated with this event
    inline const Time& time() const { return m_time; } 

    /// Information about the configuration keys associated with this event
    inline const Configuration* configuration() const { return m_config; }

    /// Translated configuration file keys for this event
    inline const LsfKeys* keys() const { return m_keys; };

    inline const MipHandlerRsdV0* mipFilter() const {
        return m_mip; }
    inline const HipHandlerRsdV0* hipFilter() const {
        return m_hip; }
    inline const DgnHandlerRsdV0* dgnFilter() const {
        return m_dgn;  }
    inline const PassthruHandlerRsdV0* passthruFilter() const {
        return m_pass;  }
    inline const GammaHandlerRsdV0* gammaFilter() const {
        return m_gamma;  }
    inline const LpaHandler* lpaHandler() const {
        return m_lpaHandler;  }


    /// set everything at once
    inline void set(const RunInfo& run, const DatagramInfo& datagram, 
		    const GemScalers& scalers,
		    const Time& time,
		    const Configuration& configuration,
		    const LsfKeys& keys) {
      m_run = run;
      m_datagram = datagram;
      m_scalers = scalers;
      m_time = time;
      if(m_config) delete m_config;
      m_config = configuration.clone();
      m_type = configuration.type();
      if(m_keys) delete m_keys;
      m_keys = keys.clone();
      m_ktype = keys.type();
    }

    // set the individual data members
    inline void setRun( const RunInfo& val) { m_run = val; };
    inline void setRunDataTransferId(unsigned int id) { m_run.setDataTransferId(id); };
    inline void setDatagram( const DatagramInfo& val) { m_datagram = val; };
    inline void setScalers( const GemScalers& val) { m_scalers = val; };
    inline void setTime( const Time& val) { m_time = val; }; 
    inline void setConfiguration( const Configuration& configuration ) {
      if (m_config) delete m_config;
      m_config = configuration.clone();
      m_type = configuration.type();
    }
    inline void setKeys( const LsfKeys& keys ) {
      if (m_keys) delete m_keys;
      m_keys = keys.clone();
      m_ktype = keys.type();
    }

void addGammaHandler(const GammaHandlerRsdV0& gamma) {
    m_gamma = new lsfData::GammaHandlerRsdV0(gamma);
}
void addDgnHandler(const DgnHandlerRsdV0& dgn) {
    m_dgn = new lsfData::DgnHandlerRsdV0(dgn);
}
void addPassthruHandler(const PassthruHandlerRsdV0& pass) {
    m_pass = new lsfData::PassthruHandlerRsdV0(pass);
}
void addMipHandler(const MipHandlerRsdV0& mip) {
    m_mip = new lsfData::MipHandlerRsdV0(mip);
}
void addHipHandler(const HipHandlerRsdV0& hip) {
    m_hip = new lsfData::HipHandlerRsdV0(hip);
}
void addLpaHandler(const LpaHandler& lpa) {
    m_lpaHandler = new lsfData::LpaHandler(lpa);
}
    
  private:
    
    /// 
    RunInfo m_run;
    DatagramInfo m_datagram;
    GemScalers m_scalers;
    Time m_time;
    Configuration* m_config;
     
    enums::Lsf::RunType m_type;
    
    LsfKeys* m_keys;
    enums::Lsf::KeysType m_ktype;

    GammaHandlerRsdV0 *m_gamma;   
    PassthruHandlerRsdV0 *m_pass;
    MipHandlerRsdV0 *m_mip;
    HipHandlerRsdV0 *m_hip;
    DgnHandlerRsdV0 *m_dgn;
    LpaHandler *m_lpaHandler;

  };

}


#endif    // LSF_METAEVENT

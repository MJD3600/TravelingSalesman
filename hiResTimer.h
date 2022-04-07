/************************************************************************
*																		*
*	File:		hiResTimer.h											*
*																		*
*	Authors:	Michael Davis											*
*																		*
*	Date:		Feb 8, 2020												*
*																		*
*	Purpose:	This file defines the CHighResTimer class				*
*																		*
************************************************************************/

#ifndef __CHIGHRESTIMER__
#define __CHIGHRESTIMER__

/************************************************************************
*																		*
*	The definition of the CHighResTimer class							*
*																		*
************************************************************************/

class CHighResTimer 
{
//	Public member functions

	public:
	
		CHighResTimer() 		
		{
			::ZeroMemory(&m_start, sizeof(m_start));
			::ZeroMemory(&m_stop, sizeof(m_stop));
	
			LARGE_INTEGER tempFreq;			
			::QueryPerformanceFrequency(&tempFreq);

			//	so we don't have to cast every time we call GetSeconds...
			m_freq = static_cast<double>(tempFreq.QuadPart);
		}

		virtual ~CHighResTimer() {}

		void StartTime() 
		{
			::QueryPerformanceCounter(&m_start);
		}
        
		double GetSeconds() 
		{
			::QueryPerformanceCounter(&m_stop);
			return((m_stop.QuadPart - m_start.QuadPart) / m_freq);
		}

		__int64 GetTicks() 
		{
			::QueryPerformanceCounter(&m_stop);
			return( m_stop.QuadPart - m_start.QuadPart );			
		}

	private:
	
		LARGE_INTEGER	m_start;
		LARGE_INTEGER	m_stop;
		double			m_freq;
};

#endif

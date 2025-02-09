
#ifndef BOOST_FSM_STATE_MACHINE_INCLUDED
#define BOOST_FSM_STATE_MACHINE_INCLUDED

// Copyright Aleksey Gurtovoy 2002-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: state_machine.hpp,v 1.1 2020/09/08 21:22:10 kurt Exp $
// $Date: 2020/09/08 21:22:10 $
// $Revision: 1.1 $

#include "aux_/event.hpp"
#include "aux_/state.hpp"
#include "aux_/transition.hpp"
#include "aux_/STT_impl_gen.hpp"
#include <boost/shared_ptr.hpp>

#include <queue>
#include <memory>
#include <cassert>

namespace fsm {

template< typename Derived >
class state_machine
{
 private:
    typedef state_machine self_t;
    typedef aux::base_event base_event_t;
    typedef boost::shared_ptr<base_event_t const> base_event_ptr_t;
    
 public: 
    typedef long state_t;
    typedef void (Derived::* invariant_func_t)() const;
    
    template< typename DerivedEvent >
    struct event
        : aux::event<DerivedEvent>
    {
    };

    void process_event(base_event_t const& evt)
    {
        // all internal events should be handled at this point
        assert(!m_events_queue.size());

        // process the external event passed
        do_transition(evt);

        // if the previous transition generated any internal events,
        // process those
        while (m_events_queue.size())
        {
            do_transition(*m_events_queue.front());
            m_events_queue.pop();
        }
    }

    state_t current_state() const
    {
        return m_state;
    }

 protected:
    // interface for the derived class

    state_machine(state_t const& initial_state)
        : m_state(initial_state)
    {
    }

    state_machine()
        : m_state(typename Derived::initial_state())
    {
    }

    virtual ~state_machine()
    {
    }


#if defined(BOOST_NO_CXX11_SMART_PTR)

    void post_event(std::auto_ptr<base_event_t const> evt)
    
#else

    void post_event(std::unique_ptr<base_event_t const> evt)
    
#endif

    {
        m_events_queue.push(base_event_ptr_t(evt.release()));
    }

    template<
          long State
#if !defined(BOOST_INTEL_CXX_VERSION) && (!defined(__GNUC__) || __GNUC__ >= 3)
        , invariant_func_t f = static_cast<invariant_func_t>(0)
#else
        , invariant_func_t f = 0
#endif
        >
    struct state
        : fsm::aux::state<Derived,State,f>
    {
    };

    template<
          typename From
        , typename Event
        , typename To
        , bool (Derived::* transition_func)(Event const&)
        >
    struct transition
        : aux::transition< Derived,From,Event,To,transition_func >
    {
    };

 private:

    void do_transition(base_event_t const& evt)
    {
        typedef typename Derived::transition_table STT_;
        typedef typename aux::STT_impl_gen< STT_ >::type STT_impl_;

        m_state = STT_impl_::do_transition(
              static_cast<Derived&>(*this)
            , m_state
            , evt
            );
    }

    state_t m_state;
    std::queue< base_event_ptr_t > m_events_queue;
};

} // namespace fsm

#endif // BOOST_FSM_STATE_MACHINE_INCLUDED

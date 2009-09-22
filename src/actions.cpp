#include "actions.h"

#include <cbplugin.h>
#include <logmanager.h>

#include "cmd_result_parser.h"
#include "definitions.h"

namespace dbg_mi
{
/*
void BreakpointAddAction::Start()
{
    wxString cmd(wxT("-break-insert "));
    cbBreakpoint &bp = m_breakpoint->Get();

    if(bp.UseCondition())
        cmd += wxT("-c ") + bp.GetCondition() + wxT(" ");
    if(bp.UseIgnoreCount())
        cmd += wxT("-i ") + wxString::Format(wxT("%d "), bp.GetIgnoreCount());

    cmd += wxString::Format(wxT("%s:%d"), bp.GetFilename().c_str(), bp.GetLine());
    m_initial_cmd = QueueCommand(cmd);
    DebugLog(wxString::Format(wxT("BreakpointAddAction::m_initial_cmd = %d\n"), m_initial_cmd));
}

void BreakpointAddAction::OnCommandResult(int32_t cmd_id)
{
    DebugLog(wxString::Format(wxT("BreakpointAddAction::OnCommandResult: %d"), cmd_id));

    if(m_initial_cmd == cmd_id)
    {
        ResultParser *result = GetCommandResult(cmd_id);
        assert(result);
        const ResultValue &value = result->GetResultValue();
        const ResultValue *number = value.GetTupleValue(wxT("bkpt.number"));
        if(number)
        {
            const wxString &number_value = number->GetSimpleValue();
            long n;
            if(number_value.ToLong(&n, 10))
            {
                DebugLog(wxString::Format(wxT("BreakpointAddAction::breakpoint index is %d"), n));
                m_breakpoint->SetIndex(n);

                if(!m_breakpoint->Get().IsEnabled())
                    QueueCommand(wxString::Format(wxT("-break-disable %d"), n));
            }
            else
                DebugLog(wxT("BreakpointAddAction::error getting the index :( "));
        }
        else
        {
            DebugLog(wxT("BreakpointAddAction::error getting number value:( "));
            DebugLog(value.MakeDebugString());
        }
    }
    else
    {

    }
}

RunAction::RunAction(cbDebuggerPlugin *plugin, const wxString &command, bool &is_stopped) :
    m_plugin(plugin),
    m_command(command),
    m_is_stopped(is_stopped)
{
}

void RunAction::Start()
{
    QueueCommand(m_command);
}
void RunAction::OnCommandResult(int32_t cmd_id)
{
    ResultParser *result = GetCommandResult(cmd_id);
    assert(result);
    if(result->GetResultClass() == ResultParser::ClassRunning)
    {
        DebugLog(wxT("RunAction success, the debugger is !stopped!"));
        m_is_stopped = false;
        m_plugin->ClearActiveMarkFromAllEditors();
    }
}

WatchAction::WatchAction(wxString const &variable_name) :
    m_variable_name(variable_name)
{
}

void WatchAction::Start()
{
    QueueCommand(wxT("-var-create ") + m_variable_name + wxT("_gdb_var * ") + m_variable_name);
}

void WatchAction::OnCommandResult(int32_t cmd_id)
{
    DebugLog(wxString::Format(wxT("WatchAction::OnCommandResult: %d"), cmd_id));

    ResultParser *result = GetCommandResult(cmd_id);
    assert(result);

    DebugLog(result->MakeDebugString());

    if(cmd_id == 0)
        QueueCommand(wxT("-var-info-type ") + m_variable_name + wxT("_gdb_var"));
    else if(cmd_id == 1)
    {
        Finish();
        return;
    }
}
*/
} // namespace dbg_mi

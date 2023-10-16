import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'
import { BrowserRouter,Routes,Route,Link } from 'react-router-dom'
import AboutPage from './Pages/About/AboutPage'
import FirstPage from './Pages/FirstPage/FirstPage'
import NavBar from './NavBar'

function App() {
  const [loggedIn,setLoggedIn]=useState(false)

  function handleSignIn(){
    alert(loggedIn==false?"Signed In Successfully":"Signed Out Successfully")
    setLoggedIn(!loggedIn)
  }

  const AuthenticatedComponent=({loggedIn,children})=>{
    // THIS IS A TEMPLATE FOR PROTECTED ROUTES, WRAP THE COMPONENT YOU WANT TO BE PROTECTED INSIDE THIS COMPONENT
    // AuthenticatedComponent template
    if(loggedIn==true){
      return(
      <>
        {children}
      </>
      )
    }else if(loggedIn==false){
      return(
        <h1>You do not have proper access to this page</h1>
      )
    }
  
  }

  return (
    <>
    
      <BrowserRouter>  
      <NavBar signIn={handleSignIn} loggedIn={loggedIn}/>
      <Routes>
        <Route path="/" element={
        <AuthenticatedComponent loggedIn={loggedIn}>
        <FirstPage/>
        </AuthenticatedComponent>
      }
        />
        <Route path="/about" element={
        <AuthenticatedComponent loggedIn={loggedIn}>
        <AboutPage/>
        </AuthenticatedComponent>
        }/>
      </Routes>
      </BrowserRouter>
      {/* ABOUT PAGE SHOULD ONLY BE ACCESSIBLE IF USER IS LOGGED IN, DISPLAY ERROR
          NO ACCESS TO THIS PAGE IF USER IS NOT SIGNED IN*/}
    </>
  )
}

export default App
